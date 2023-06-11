#pragma once

#include <map>
#include <string>
#include <vector>

namespace serialization {

struct BaseObject {
  void FillWithDefault() {
    boolean = true;
    floating_point = 3.14159265359;
    integer = 123456;
    str = "All work and no play makes Jack a dull boy";
    int_array = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 9};
    map_string_int = {{"biba", 1}, {"boba", 2}};
  };

  bool boolean;
  double floating_point;
  uint64_t integer;
  std::string str;
  std::vector<uint64_t> int_array;
  std::map<std::string, uint64_t> map_string_int;
};

} // namespace serialization
