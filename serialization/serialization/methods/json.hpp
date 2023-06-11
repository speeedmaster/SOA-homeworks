#pragma once

#include <nlohmann/json.hpp>

#include <serialization/methods/base.hpp>
#include <serialization/objects/base.hpp>


namespace serialization {

struct JsonObject : public BaseObject {};

inline void to_json(nlohmann::json &j, const JsonObject &obj) {
  j = nlohmann::json{
    {"boolean", obj.boolean},
    {"floating_point", obj.floating_point},
    {"integer", obj.integer},
    {"str", obj.str},
    {"int_array", obj.int_array},
    {"map_string_int", obj.map_string_int}
  };
}

inline void from_json(const nlohmann::json& j, JsonObject& obj) {
  j.at("boolean").get_to(obj.boolean);
  j.at("floating_point").get_to(obj.floating_point);
  j.at("integer").get_to(obj.integer);
  j.at("str").get_to(obj.str);
  j.at("int_array").get_to(obj.int_array);
  j.at("map_string_int").get_to(obj.map_string_int);
}

class JsonSerialization : public SerializationMethodBase {
 public:
  JsonSerialization() {
    object_.FillWithDefault();
  }

  ~JsonSerialization() = default;

  uint64_t GetSerializedObjectSize() override {
    Serialize();
    return nlohmann::to_string(data_).size();
  }

  void Serialize() override {
    data_ = object_;
  }

  void Deserialize() override { object_ = data_.get<JsonObject>(); }

  uint64_t GetRunsCount() override {
    return 1000;
  }

  std::string GetMethodNameForResponce() override { return "json    "; };

private:
  JsonObject object_;
  nlohmann::json data_;
};

} // namespace serialization
