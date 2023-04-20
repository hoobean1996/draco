# cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_TOOLCHAIN_FILE /home/parallels/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(CMAKE_CXX_STANDARD 17)


cmake_minimum_required(VERSION 3.10)

project(draco)



find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)

enable_testing()
find_package(GTest CONFIG REQUIRED)
add_test(AllTestsInMain main)


add_executable(draco src/main.cpp)
target_link_libraries(draco PRIVATE glog::glog)
target_link_libraries(draco PRIVATE gflags::gflags)
target_link_libraries(main PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

