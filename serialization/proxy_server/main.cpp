#include <protocol/multicast.hpp>
#include <boost/log/trivial.hpp>

#include <helpers/env.hpp>

#include <proxy_server/query_dispatcher/dispatcher.hpp>

namespace {

const std::string kProxyPortVarName = "PROXY_PORT";
const std::string kWorkerPortVarName = "WORKER_PORT";

}

int main(int argc, char** argv) {
  auto port_settings =
      helpers::env::GetEnvValues({kProxyPortVarName, kWorkerPortVarName});

  if (!port_settings) {
    BOOST_LOG_TRIVIAL(error)
        << "Some env variables are missing. Please set " << kProxyPortVarName
        << " and " << kWorkerPortVarName;
    return 1;
  }

  auto proxy_port = std::stoi(port_settings->at(kProxyPortVarName));
  auto worker_port = std::stoi(port_settings->at(kWorkerPortVarName));

  auto multicast_settings = protocol::multicast::GetSettingsFromEnv();

  try {
    boost::asio::io_context io_context;
    proxy_server::query_dispatcher::Dispatcher query_dispatcher(
        io_context, proxy_port, worker_port, multicast_settings);
    io_context.run();
  } catch (const std::exception& ex) {
    BOOST_LOG_TRIVIAL(error) << "Error in proxy_server occured: " << ex.what();
  }
  return 0;
}