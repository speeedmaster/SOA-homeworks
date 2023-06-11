set(LIB_NAME helpers_lib)

file(GLOB_RECURSE HELPERS_LIB_SRCS "*.cpp" "*.cc")

add_library(${LIB_NAME} ${HELPERS_LIB_SRCS})

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
