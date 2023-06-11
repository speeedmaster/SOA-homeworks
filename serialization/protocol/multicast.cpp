#include "multicast.hpp"

#include <helpers/env.hpp>

namespace protocol::multicast  {

static const std::string kMulticastIPVarName = "MULTICAST_IP";
static const std::string kMulticasPortVarName = "MULTICAST_PORT";

std::optional<MulticastSettings> GetSettingsFromEnv() {
  auto multicast_settings =
      helpers::env::GetEnvValues({kMulticastIPVarName, kMulticasPortVarName});
  if (!multicast_settings) {
    return std::nullopt;
  }
  MulticastSettings result;
  result.ip_address = boost::asio::ip::address::from_string(multicast_settings->at(kMulticastIPVarName));
  result.port = std::stoi(multicast_settings->at(kMulticasPortVarName));
  return result;
}

} // namespace protocol::multicast 
