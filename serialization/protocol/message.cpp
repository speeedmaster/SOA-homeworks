#include "message.hpp"

#include <boost/log/trivial.hpp>

namespace protocol::message {

namespace {

static const std::string kGetType = "get";
static const std::string kGetAllType = "get_all";
static const std::string kWorkerResponseType = "worker_response";
static const std::string kUnknownType = "unknown";

} // namespace

std::string ToString(const MessageType& type) {
  switch (type) {
    case MessageType::GET:
        return kGetType;
    case MessageType::GET_ALL:
        return kGetAllType;
    case MessageType::WORKER_RESPONSE:
      return kWorkerResponseType;
    default:
        return kUnknownType;
  }
}

MessageType Message::GetType() const {
  if (method == kGetType) {
    return MessageType::GET;
  }
  if (method == kGetAllType) {
    return MessageType::GET_ALL;
  }
  if (method == kWorkerResponseType) {
    return MessageType::WORKER_RESPONSE;
  }
  return MessageType::UNKNOWN;
}

nlohmann::json Message::Json() const {
  return nlohmann::json{
      {"method", method},
      {"args", args},
  };
}

void from_json(const nlohmann::json &json, Message &obj) {
  json.at("method").get_to(obj.method);
  json.at("args").get_to(obj.args);
}

void to_json(nlohmann::json& json, const Message& obj) {
  json = nlohmann::json{
      {"method", obj.method},
      {"args", obj.args},
  };
}

std::optional<Message> Parse(const std::string &text, std::string& err) {
  try {
    return nlohmann::json::parse(text).get<Message>();
  } catch (const std::exception& ex) {
    BOOST_LOG_TRIVIAL(error) << "Message parse error: " << ex.what();
    err = ex.what();
    return std::nullopt;
  }
}

} // protocol::message
