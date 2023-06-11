#include "dispatcher.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <boost/log/trivial.hpp>

#include <fmt/core.h>

namespace proxy_server::query_dispatcher {

namespace {

udp::socket GetSocket(boost::asio::io_context& io_context, uint32_t port) {
  udp::socket socket(io_context, udp::endpoint(udp::v4(), port));
  socket.set_option(udp::socket::reuse_address(true));
  return socket;
}

}

Dispatcher::Dispatcher(boost::asio::io_context &io_context,
                       uint32_t listen_port, uint32_t worker_port,
                       std::optional<MulticastSettings> &multicast_settings,
                       uint32_t data_length)
    : worker_port_{worker_port}, socket_(GetSocket(io_context, listen_port)),
      resolver_(io_context), recv_buffer_(data_length) {
  if (multicast_settings) {
    multicast_endpoint_ =
        udp::endpoint(multicast_settings->ip_address, multicast_settings->port);
  }

  RecieveNext();
}


void Dispatcher::RecieveNext() {
  socket_.async_receive_from(
      boost::asio::buffer(recv_buffer_),
      remote_endpoint_,
      boost::bind(&Dispatcher::HandleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
  );
}


void Dispatcher::HandleReceive(const boost::system::error_code& error, std::size_t bytes_received) {
  if (error) {
    BOOST_LOG_TRIVIAL(info) << "Received error: " << error.message();
    return;
  }

  std::string data(recv_buffer_.begin(), recv_buffer_.begin() + bytes_received);
  boost::algorithm::trim(data);

  BOOST_LOG_TRIVIAL(info) << "Received some data: " << data;

  std::string parse_err;
  auto message_opt = protocol::message::Parse(data, parse_err);
  if (!message_opt) 
  {
    socket_.async_send_to(
        boost::asio::buffer(
            fmt::format("couldn't parse message: {}\n", parse_err)),
        remote_endpoint_,
        boost::bind(&Dispatcher::HandleSend, this, remote_endpoint_,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
    RecieveNext();
    return;
  }

  auto [message, endpoint] = HandleMessage(*message_opt);

  socket_.async_send_to(boost::asio::buffer(std::move(message)), endpoint,
    boost::bind(&Dispatcher::HandleSend, this,
      endpoint,
      boost::asio::placeholders::error,
      boost::asio::placeholders::bytes_transferred)
  );
  RecieveNext();
}

std::optional<udp::endpoint> Dispatcher::GetWorkerEndpoint(const std::string& host, uint32_t port) {
  BOOST_LOG_TRIVIAL(info) << fmt::format("trying to resolve worker at {}:{}", host, port);
  try {
    udp::resolver::query query(boost::asio::ip::udp::v4(), host,
                               std::to_string(port));
    auto endpoint = resolver_.resolve(query).begin()->endpoint();
    return endpoint;
  } catch (const std::exception& ex) {
    BOOST_LOG_TRIVIAL(error)
        << "Error occured while trying to resolve worker endpoint: "
        << ex.what();
    return std::nullopt;
  }
}

std::pair<std::string, udp::endpoint> Dispatcher::HandleMessage(const Message& message) {
  switch (message.GetType()) {
    case protocol::message::MessageType::GET: {
      if (message.args.size() == 0) {
        BOOST_LOG_TRIVIAL(error) << "empty query args for method " << message.method;
        return {"invalid quiery", remote_endpoint_};
      }
      if (message.args.size() > 1) {
        BOOST_LOG_TRIVIAL(warning)
            << "got more than one arg for method  " << message.method
            << ". Will try to run with the first one";
      }

      auto endpoint = GetWorkerEndpoint(message.args[0], worker_port_);

      if (!endpoint.has_value()) {
        return {"unknown method(couldn't resolve worker)\n", remote_endpoint_};
      }

      Message worker_message;
      worker_message.method = message.method;
      worker_message.args = {remote_endpoint_.address().to_string(), std::to_string(remote_endpoint_.port())};

      nlohmann::json worker_message_json = worker_message;
      auto text = nlohmann::to_string(worker_message_json);

      return {std::move(text), std::move(*endpoint)};
    }
    case protocol::message::MessageType::GET_ALL: {
      if (!multicast_endpoint_) 
      {
        BOOST_LOG_TRIVIAL(error) << "multicast is not configured";
        return {"multicast is not configured", remote_endpoint_};
      }

      Message worker_message;
      worker_message.method = message.method;
      worker_message.args = {remote_endpoint_.address().to_string(), std::to_string(remote_endpoint_.port())};

      nlohmann::json worker_message_json = worker_message;
      auto text = nlohmann::to_string(worker_message_json);

      return {std::move(text), *multicast_endpoint_};
    }
    case protocol::message::MessageType::WORKER_RESPONSE: {
      auto text = message.args[0];

      auto user_ip = message.args[1];
      auto user_port = std::stoi(message.args[2]);
      auto endpoint = udp::endpoint(
          boost::asio::ip::address::from_string(user_ip), user_port);

      return {std::move(text), std::move(endpoint)};
    }
    default: {
      return {"unknown message", remote_endpoint_};
    }
  }
}

void Dispatcher::HandleSend(const udp::endpoint& endpoint,
                            const boost::system::error_code &error,
                            std::size_t bytes_sent) {
  if (error) {
    BOOST_LOG_TRIVIAL(warning) << "Couldn't send message: " << error.message();
    return;
  }
}

} // namespace proxy_server::query_dispatcher