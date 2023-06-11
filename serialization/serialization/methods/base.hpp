#pragma once

#include <cmath>
#include <cstdint>
#include <ctime>
#include <string>

#include <fmt/core.h>


namespace serialization {

class SerializationMethodBase {
 public:
   struct SerializationTestResult {
     uint64_t serialization_time;
     uint64_t deserialization_time;
   };

  virtual ~SerializationMethodBase() = default;

  std::string GetTestResult();

protected:
  SerializationTestResult RunTestImpl();

  virtual uint64_t GetRunsCount() = 0;
  virtual uint64_t GetSerializedObjectSize() = 0;
  virtual std::string GetMethodNameForResponce() = 0;
  virtual void Serialize() = 0;
  virtual void Deserialize() = 0;
};

} // namespace serialization
