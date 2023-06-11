#pragma once

#include <protocol/message.hpp>
#include <protocol/multicast.hpp>
#include <cstdint>
#include <vector>

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

namespace proxy_server::query_dispatcher {

using protocol::message::Message;
using protocol::multicast::MulticastSettings;

using boost::asio::ip::udp;

class Dispatcher {
 public:
   Dispatcher(boost::asio::io_context &io_context, uint32_t listening_port,
              uint32_t worker_port,
              std::optional<MulticastSettings> &multicast_settings,
              uint32_t data_length = 1024);

 private:
   void RecieveNext();
   void HandleReceive(const boost::system::error_code &error,
                      std::size_t bytes_transferred);

   void HandleSend(const udp::endpoint &, const boost::system::error_code &,
                   std::size_t bytes_sent);

   std::optional<udp::endpoint> GetWorkerEndpoint(const std::string &host,
                                              uint32_t port);

   std::pair<std::string, udp::endpoint> HandleMessage(const Message &message);

 private:
  std::vector<char> recv_buffer_;

  udp::socket socket_;
  udp::resolver resolver_;
  udp::endpoint remote_endpoint_;

  uint32_t worker_port_;
  std::optional<udp::endpoint> multicast_endpoint_;
};

} // namespace proxy_server::query_dispatcher