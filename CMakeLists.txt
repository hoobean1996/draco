# cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE /home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_STANDARD 17)


cmake_minimum_required(VERSION 3.10)

project(draco)

find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(src/)

enable_testing()
add_subdirectory(test/compiler)
include(GoogleTest)