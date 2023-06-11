#pragma once

#include <msgpack/msgpack.hpp>

#include <serialization/methods/base.hpp>
#include <serialization/objects/base.hpp>


namespace serialization {

struct MsgPackObject: public BaseObject {
  template <class T> void pack(T &pack) {
    pack(boolean, floating_point, integer, str, int_array, map_string_int);
  }
};

class MsgPackSerialization : public SerializationMethodBase {
 public:
  MsgPackSerialization() {
    object_.FillWithDefault();
  }

  ~MsgPackSerialization() = default;

  uint64_t GetSerializedObjectSize() override {
    Serialize();
    return bytes_.size();
  }

   void Serialize() override {
    bytes_ = msgpack::pack(object_);
  }

  void Deserialize() override {
    object_ = msgpack::unpack<MsgPackObject>(bytes_);
  }

  uint64_t GetRunsCount() override {
    return 1000;
  }

  std::string GetMethodNameForResponce() override { return "msgpack "; };

private:
  MsgPackObject object_;
  std::vector<uint8_t> bytes_;
};

} // namespace serialization
