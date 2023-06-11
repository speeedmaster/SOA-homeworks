#pragma once

#include <vector>

#include <boost/asio/ip/udp.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/bind/bind.hpp>
#include <boost/asio.hpp>
#include <boost/format.hpp>

#include <serialization/methods/builder.hpp>


namespace worker::server {

using boost::asio::ip::udp;

class Listener {
public:
  Listener(const serialization::SerializationMethodBuilder &methods_builder,
           udp::socket socket, boost::asio::thread_pool &thread_pool_,
           uint32_t data_length = 1024);

private:
  void ReceiveNext();

  void HandleReceive(const boost::system::error_code& error, std::size_t bytes_transferred);

  void HandleSend(const udp::endpoint &, const boost::system::error_code &,
                  std::size_t);

  void HandleReceiveImpl(const std::string& data, const udp::endpoint& remote_endpoint);

private:
  udp::socket socket_;
  udp::endpoint remote_endpoint_;
  std::vector<char> recv_buffer_;
  const serialization::SerializationMethodBuilder &methods_builder;
  boost::asio::thread_pool &thread_pool_;
};

} // worker::server