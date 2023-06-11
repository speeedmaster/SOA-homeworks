#include "env.hpp"

namespace helpers::env {

std::optional<std::string> GetEnvValue(const std::string& env_name) {
    char* env_var = std::getenv(env_name.c_str());
    if (!env_var) {
      return std::nullopt;
    }
    return env_var;
}

std::optional<std::unordered_map<std::string, std::string>>
GetEnvValues(const std::vector<std::string> &env_names) {
    std::unordered_map<std::string, std::string> result;
    for (const auto& env_name : env_names) {
        auto env_value = GetEnvValue(env_name);
        if (!env_value) {
          return std::nullopt;
        }
        result[env_name] = std::move(*env_value);
    }
    return result;
}

} // namespace helpers::env
