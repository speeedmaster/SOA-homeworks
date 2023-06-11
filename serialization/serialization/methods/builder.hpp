#pragma once

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <serialization/methods/base.hpp>
#include <serialization/methods/json.hpp>
#include <serialization/methods/msgpack.hpp>
#include <serialization/methods/native.hpp>
#include <serialization/methods/protobuf/protobuf.hpp>
#include <serialization/methods/xml.hpp>
#include <serialization/methods/yaml.hpp>

namespace serialization {

namespace {

static const std::map<
    std::string, std::function<std::unique_ptr<SerializationMethodBase>(void)>>
    kMethodBuilders = {
        {"native", []() { return std::make_unique<NativeSerialization>(); }},
        {"xml", []() { return std::make_unique<XMLSerialization>(); }},
        {"json", []() { return std::make_unique<JsonSerialization>(); }},
        {"protobuf",
         []() { return std::make_unique<ProtoBufSerialization>(); }},
        {"yaml", []() { return std::make_unique<YamlSerialization>(); }},
        {"msgpack", []() { return std::make_unique<MsgPackSerialization>(); }}};

} // namespace

class SerializationMethodBuilder {
public:
  SerializationMethodBuilder(const std::string &method_name)
      : method_name_(method_name) {
    if (!MethodSupported(method_name)) {
      throw std::logic_error("trying to initialize SerializationMethodBuilder "
                             "with invalid method");
    }
}

  std::unique_ptr<SerializationMethodBase>
  BuildMethod() const {
    return kMethodBuilders.at(method_name_)();
  }

  static bool MethodSupported(const std::string &method_name) {
    return kMethodBuilders.count(method_name) != 0;
  }

 private:
  std::string method_name_;
  std::function<std::unique_ptr<SerializationMethodBase>(void)> builder_;
};

} // namespace serialization