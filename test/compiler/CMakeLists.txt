enable_testing()
add_executable(compiler_graphql_token_test
 compiler_test.cpp
../../src/compiler/token.cpp
../../src/compiler/source.cpp)
target_link_libraries(compiler_graphql_token_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(compiler_graphql_token_test TEST_PREFIX TokenTest)