#pragma once

#include <cstdint>

#include <serialization/methods/base.hpp>
#include <serialization/methods/protobuf/base.pb.h>
#include <string>

namespace serialization {

class ProtoBufSerialization : public SerializationMethodBase {
 public:
  ProtoBufSerialization() {
    std::vector<uint64_t> int_array{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};

    object_.set_boolean(true);
    object_.set_floating_point(3.14159265359);
    object_.set_integer(123456);
    object_.set_str("All work and no play makes Jack a dull boy");
    for (auto i : int_array) {
      object_.add_int_array(i);
    }
    auto& map = *object_.mutable_map_string_int();
    map["str_1"] = 1;
    map["str_2"] = 2;
  }

  ~ProtoBufSerialization() = default;

  uint64_t GetSerializedObjectSize() override {
    Serialize();
    return data_.size();
  }

  void Serialize() override { object_.SerializeToString(&data_); }

  void Deserialize() override {
    object_.ParseFromString(data_);
    ;
  }

  uint64_t GetRunsCount() override {
    return 1000;
  }

  std::string GetMethodNameForResponce() override { return "protobuf"; };

private:
  protobuf_serialization::Object object_;
  std::string data_;
};

} // namespace serialization
