include(FetchContent)

# nlohmann_json
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# fmt
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.0.0
)
FetchContent_MakeAvailable(fmt)

# Catch2 (Message pack)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.3.2
)
FetchContent_MakeAvailable(Catch2)

# Message pack
FetchContent_Declare(
    Msgpack
    GIT_REPOSITORY https://github.com/mikeloomisgg/cppack
    GIT_TAG 51655ec8f2b8fed84f685e3bcf8f226b139a263b
)
FetchContent_MakeAvailable(Msgpack)

# yaml
FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp
    GIT_TAG yaml-cpp-0.7.0
)
FetchContent_MakeAvailable(yaml-cpp)

# protocol-buffers
FetchContent_Declare(
    protobuf
    GIT_REPOSITORY https://github.com/protocolbuffers/protobuf
    GIT_TAG v23.2
)
FetchContent_MakeAvailable(protobuf)
