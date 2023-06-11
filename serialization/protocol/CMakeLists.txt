set(LIB_NAME protocol_lib)

file(GLOB_RECURSE PROTOCOL_LIB_SRCS "*.cpp" "*.cc")

add_library(${LIB_NAME} ${PROTOCOL_LIB_SRCS})

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

find_package(Boost 1.71.0 REQUIRED system log)

target_link_libraries(${LIB_NAME} PRIVATE Boost::system Boost::log)
target_link_libraries(${LIB_NAME} PRIVATE nlohmann_json)
