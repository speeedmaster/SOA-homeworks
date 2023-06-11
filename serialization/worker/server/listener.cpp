#include "listener.hpp"

#include <protocol/message.hpp>

#include <boost/log/trivial.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/post.hpp>

namespace worker::server {

Listener::Listener(
    const serialization::SerializationMethodBuilder &methods_builder,
    udp::socket socket, boost::asio::thread_pool &thread_pool,
    uint32_t data_length)
    : socket_(std::move(socket)), recv_buffer_(data_length, 0),
      methods_builder(methods_builder), thread_pool_(thread_pool) {
  ReceiveNext();
}

void Listener::ReceiveNext() {
  socket_.async_receive_from(
      boost::asio::buffer(recv_buffer_),
      remote_endpoint_,
      boost::bind(&Listener::HandleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred)
  );
}

void Listener::HandleReceiveImpl(const std::string &data,
                                 const udp::endpoint &remote_endpoint) {
  std::string parse_err;
  auto message_opt = protocol::message::Parse(data, parse_err);
  if (!message_opt) 
  {
    BOOST_LOG_TRIVIAL(info)
        << "Invalid request: " << data << ". Will not respond";
    return;
  }

  auto serialization_method = methods_builder.BuildMethod();

  protocol::message::Message response;
  response.method = ToString(protocol::message::MessageType::WORKER_RESPONSE);
  response.args.push_back(serialization_method->GetTestResult());
  response.args.insert(response.args.end(), message_opt->args.begin(), message_opt->args.end());

  socket_.async_send_to(
      boost::asio::buffer(nlohmann::to_string(response.Json())),
      remote_endpoint,
      boost::bind(&Listener::HandleSend, this, remote_endpoint,
                  boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
}

void Listener::HandleReceive(const boost::system::error_code& error, std::size_t bytes_received) {
  if (error) {
    BOOST_LOG_TRIVIAL(info) << "Received error: " << error.message();
    return;
  }

  std::string data(recv_buffer_.begin(), recv_buffer_.begin() + bytes_received);
  boost::algorithm::trim(data);

  BOOST_LOG_TRIVIAL(info) << "Received: " << data;

  boost::asio::post(thread_pool_, [this, data = std::move(data),
                                   remote_endpoint = remote_endpoint_]() {
    HandleReceiveImpl(data, remote_endpoint);
  });

  ReceiveNext();
}

void Listener::HandleSend(const udp::endpoint& endpoint,
                            const boost::system::error_code &error,
                            std::size_t bytes_sent) {
  if (error) {
    BOOST_LOG_TRIVIAL(warning) << "Couldn't send message: " << error.message();
    return;
  }
}

} // namespace worker::server