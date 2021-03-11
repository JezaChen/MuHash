cmake_minimum_required(VERSION 3.13.4)
project(muhash)

set(CMAKE_CXX_STANDARD 14)

find_package(cryptopp CONFIG REQUIRED)


add_executable(muhash main.cpp muhash.cpp uint256.cpp chacha20.cpp util.h util.cpp)
target_link_libraries(muhash PRIVATE cryptopp-static)