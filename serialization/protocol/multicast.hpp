#pragma once

#include <boost/asio/ip/address.hpp>
#include <optional>

namespace protocol::multicast {

struct MulticastSettings {
    boost::asio::ip::address ip_address;
    int port;
};

std::optional<MulticastSettings> GetSettingsFromEnv();

} // namespace protocol::multicast 
