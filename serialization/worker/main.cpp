#include <boost/asio.hpp>
#include <boost/log/trivial.hpp>

#include <helpers/env.hpp>
#include <worker/server/listener.hpp>
#include <protocol/multicast.hpp>

#include <proxy_server/query_dispatcher/dispatcher.hpp>

namespace {

using boost::asio::ip::udp;
using worker::server::Listener;

const std::string kMethodVarName = "METHOD";
const std::string kPortVarName = "PORT";

udp::socket MakeUnicastSocket(boost::asio::io_context& io_context, uint32_t port) {
  udp::socket socket(io_context, udp::endpoint(udp::v4(), port));
  socket.set_option(udp::socket::reuse_address(true));
  return socket;
}

udp::socket MakeMulticastSocket(boost::asio::io_context& io_context, boost::asio::ip::address multicast_ip, uint32_t multicast_port) {
  BOOST_LOG_TRIVIAL(info) << "setting up multicast soket: " << multicast_ip << ":" << multicast_port;
  udp::socket socket(io_context);
  socket.open(boost::asio::ip::udp::v4());
  socket.set_option(udp::socket::reuse_address(true));
  // socket.bind(
  //     udp::endpoint(boost::asio::ip::address_v4::any(), multicast_port));
  socket.bind(udp::endpoint(multicast_ip, multicast_port));
  socket.set_option(boost::asio::ip::multicast::join_group(multicast_ip));
  return socket;
}

}

int main(int argc, char** argv) {
  auto worker_settings =
      helpers::env::GetEnvValues({kMethodVarName, kPortVarName});

  if (!worker_settings) {
    BOOST_LOG_TRIVIAL(error)
        << "Some env variables are missing. Please set " << kMethodVarName
        << " and " << kPortVarName;
    return 1;
  }

  auto port = std::stoi(worker_settings->at(kPortVarName));
  auto method = worker_settings->at(kMethodVarName);

  if (!serialization::SerializationMethodBuilder::MethodSupported(method)) {
    BOOST_LOG_TRIVIAL(error) << "Serialization method " << method
                             << " is not supported, try another one";
  }
  serialization::SerializationMethodBuilder method_builder(method);

  auto multicast_settings = protocol::multicast::GetSettingsFromEnv();

  std::unique_ptr<Listener> unicast_listener;
  std::unique_ptr<Listener> multicast_listener;

  boost::asio::thread_pool thread_pool(std::thread::hardware_concurrency());
  try {
    boost::asio::io_context io_context;

    unicast_listener.reset(new Listener(
        method_builder, MakeUnicastSocket(io_context, port), thread_pool));
    if (multicast_settings) {
      multicast_listener.reset(new Listener(
          method_builder,
          MakeMulticastSocket(io_context, multicast_settings->ip_address,
                              multicast_settings->port),
          thread_pool));
    } else {
      BOOST_LOG_TRIVIAL(error) << "fuuuuck";
    }
    io_context.run();
  } catch (std::exception& ex) {
    BOOST_LOG_TRIVIAL(error) << "Error in worker occured: " << ex.what();
  }
  return 0;
}