cmake_minimum_required(VERSION 3.13.4)

project(tamachan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS protos/message.proto)

add_subdirectory(external/abseil)

add_executable(tamachan tamachan.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(tamachan ${Protobuf_LIBRARIES})
