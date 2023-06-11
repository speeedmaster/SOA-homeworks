set(BIN_NAME proxy-server-bin)

file(GLOB_RECURSE PROXY_SERVER_SRCS "*.cpp" "*.cc")

add_executable(${BIN_NAME} ${PROXY_SERVER_SRCS})

find_package(Boost 1.71.0 REQUIRED log system coroutine)

target_include_directories(${BIN_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${BIN_NAME} PRIVATE Boost::log Boost::system Boost::coroutine)
target_link_libraries(${BIN_NAME} PRIVATE nlohmann_json)
target_link_libraries(${BIN_NAME} PRIVATE helpers_lib)
target_link_libraries(${BIN_NAME} PRIVATE protocol_lib)
target_link_libraries(${BIN_NAME} PRIVATE fmt)
