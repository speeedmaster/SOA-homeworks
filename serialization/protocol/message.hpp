#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <optional>


namespace protocol::message {

enum class MessageType {
  GET,
  GET_ALL,
  WORKER_RESPONSE,
  UNKNOWN,
};

struct Message {
std::string method;
std::vector<std::string> args;

MessageType GetType() const;

nlohmann::json Json() const;
};

void from_json(const nlohmann::json& json, Message& obj);

void to_json(nlohmann::json& json, const Message& obj);

std::string ToString(const MessageType&);
std::optional<Message> Parse(const std::string &text, std::string& err);

} // namespace protocol::message
