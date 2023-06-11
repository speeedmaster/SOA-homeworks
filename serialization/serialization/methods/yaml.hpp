#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include <fmt/core.h>

#include <yaml-cpp/yaml.h>

#include <serialization/methods/base.hpp>
#include <serialization/objects/base.hpp>

namespace serialization {

 struct YamlObject : public BaseObject {};

 } // namespace serialization

namespace YAML {

template<>
struct convert<serialization::YamlObject> {
  static Node encode(const serialization::YamlObject& rhs) {
    Node node;
    node["boolean"] = rhs.boolean;
    node["floating_point"] = rhs.floating_point;
    node["integer"] = rhs.integer;
    node["str"] = rhs.str;
    node["int_array"] = rhs.int_array;
    node["map_string_int"] = rhs.map_string_int;
    return node;
  }

  static bool decode(const Node &node, serialization::YamlObject &rhs) {
    rhs.boolean = node["boolean"].as<bool>();
    rhs.floating_point = node["floating_point"].as<double>();
    rhs.integer = node["integer"].as<uint64_t>();
    rhs.str = node["str"].as<std::string>();
    rhs.int_array = node["int_array"].as<std::vector<uint64_t>>();
    rhs.map_string_int =
        node["map_string_int"].as<std::map<std::string, uint64_t>>();
    return true;
  }
};

}

namespace serialization {

class YamlSerialization : public SerializationMethodBase {
 public:
  YamlSerialization() {
    object_.FillWithDefault();
  }

  ~YamlSerialization() = default;

  uint64_t GetSerializedObjectSize() override {
    Serialize();
    YAML::Emitter emmiter;
    emmiter << data_;
    return emmiter.size();
  }

  void Serialize() override {
    data_ = object_;
  }

  void Deserialize() override {
    object_ = data_.as<YamlObject>();
  }

  uint64_t GetRunsCount() override {
    return 10000;
  }

  std::string GetMethodNameForResponce() override { return "yaml    "; }

private:
  YamlObject object_;
  YAML::Node data_;
};

} // namespase serialization
