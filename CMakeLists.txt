cmake_minimum_required(VERSION 3.13.4)

# set(CMAKE_TOOLCHAIN_FILE /home/jeza/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(muhash)

set(CMAKE_CXX_STANDARD 17)


# set(CMAKE_PREFIX_PATH /home/jeza/vcpkg/packages/)
# find_package(cryptopp CONFIG REQUIRED)

add_executable(muhash main.cpp muhash.cpp uint256.cpp chacha20.cpp util.h util.cpp base64.h sha256.h sha256.cpp)
# target_link_libraries(muhash PRIVATE cryptopp-static)