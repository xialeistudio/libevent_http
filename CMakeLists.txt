cmake_minimum_required(VERSION 3.9)
project(libevent_http C)

set(CMAKE_C_STANDARD 99)

add_executable(libevent_http main.c)

target_link_libraries(libevent_http event)