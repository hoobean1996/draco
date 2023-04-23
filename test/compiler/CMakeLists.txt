# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(compiler_graphql_token_test)

# 添加测试
enable_testing()
add_executable(${PROJECT_NAME}
    compiler_test.cpp
    ../../src/compiler/token.cpp
    ../../src/compiler/source.cpp
    ../../src/compiler/lexer.cpp
)
target_link_libraries(${PROJECT_NAME}
    PRIVATE GTest::gtest
            GTest::gtest_main
            GTest::gmock
            GTest::gmock_main
            Folly::folly
            Folly::folly_deps
            Folly::follybenchmark
            Folly::folly_test_util
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME} TEST_PREFIX TokenTest)

# 查找 folly 库
find_package(folly CONFIG REQUIRED)

# 添加依赖
target_link_libraries(${PROJECT_NAME}
    PRIVATE Folly::folly
            Folly::folly_deps
            Folly::follybenchmark
            Folly::folly_test_util
)
