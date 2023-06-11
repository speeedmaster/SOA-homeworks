#include "base.hpp"

#include <cmath>
#include <cstdint>
#include <ctime>
#include <string>

#include <fmt/core.h>


namespace serialization {

namespace {

// average in runs_count times run time in nanoseconds
template <class F> uint64_t RunAndMeasureAvgTime(F &fun, uint64_t runs_count) {
  uint64_t ticks = 0;
  for (uint64_t i = 0; i < runs_count; ++i) {
    const auto start_time = clock();
    fun();
    ticks += (clock() - start_time);
  }
  return std::round(((double)ticks / runs_count) * (double(1e9) / CLOCKS_PER_SEC));
}

} // namespace

std::string SerializationMethodBase::GetTestResult() {
  auto test_result = RunTestImpl();
  return fmt::format("{} -   {}b\t- {}ns\t- {}ns\n",
                     GetMethodNameForResponce(), GetSerializedObjectSize(),
                     test_result.serialization_time,
                     test_result.deserialization_time);
}

SerializationMethodBase::SerializationTestResult
SerializationMethodBase::RunTestImpl() {
  const auto serialization_func = [this]() { Serialize(); };
  const auto deserialization_func = [this]() { Deserialize(); };

  const auto runs_count = GetRunsCount();

  return {.serialization_time =
              RunAndMeasureAvgTime(serialization_func, runs_count),
          .deserialization_time =
              RunAndMeasureAvgTime(deserialization_func, runs_count)};
}

} // namespace serialization
