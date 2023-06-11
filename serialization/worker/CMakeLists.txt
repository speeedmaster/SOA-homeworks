set(BIN_NAME worker-bin)

file(GLOB_RECURSE WORKER_SRCS "*.cpp" "*.cc")

add_executable(${BIN_NAME} ${WORKER_SRCS})

find_package(Boost 1.71.0 REQUIRED log system coroutine serialization program_options regex)

target_include_directories(${BIN_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${BIN_NAME} PRIVATE Boost::log Boost::system Boost::coroutine Boost::serialization Boost::program_options Boost::regex)
target_link_libraries(${BIN_NAME} PRIVATE helpers_lib)
target_link_libraries(${BIN_NAME} PRIVATE protocol_lib)
target_link_libraries(${BIN_NAME} PRIVATE serialization_lib)
target_link_libraries(${BIN_NAME} PRIVATE fmt)
target_link_libraries(${BIN_NAME} PRIVATE nlohmann_json)
target_link_libraries(${BIN_NAME} PRIVATE yaml-cpp)
target_link_libraries(${BIN_NAME} PRIVATE Catch2)
target_link_libraries(${BIN_NAME} PRIVATE Msgpack)
