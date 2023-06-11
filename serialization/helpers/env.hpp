#pragma once

#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace helpers::env {

std::optional<std::string> GetEnvValue(const std::string &env_name);

std::optional<std::unordered_map<std::string, std::string>>
GetEnvValues(const std::vector<std::string> &env_names);

} // namespace helpers::env