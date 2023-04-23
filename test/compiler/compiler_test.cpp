#include "../../include/compiler/source.h"
#include "../../include/compiler/token.h"
#include <gtest/gtest.h>

TEST(TokenTest, TC1) {
  using draco::graphql::Token;
  Token t;
  EXPECT_EQ(t.GetTokenKind(), draco::graphql::ILLEGAL);
  Token t2(draco::graphql::INTEGER, "3", 0, 0);
  EXPECT_EQ(t2.GetTokenKind(), draco::graphql::INTEGER);
  EXPECT_EQ(t2.GetValue(), "3");
  EXPECT_EQ(t2.GetPosition(), std::make_pair(0, 0));
}

TEST(SourceTest, TC1) {
  using draco::graphql::Source;
  Source s;
  EXPECT_EQ(s.GetSize(), 0);

  const std::string sourceCode = R"(#include <iostream>
int main(int argc, char** argv) {
  return 0;
})";

  Source s2("main.cpp", sourceCode);
  EXPECT_EQ(s2.GetFilename(), "main.cpp");
  EXPECT_EQ(s2.GetSize(), sourceCode.size());
  EXPECT_EQ(s2.GetContent(), sourceCode);
  s2.PrepareLines();
  EXPECT_EQ(s2.GetLineCount(), 4);
  std::vector<std::string> expectLines = {"#include <iostream>",
                                          "int main(int argc, char** argv) {",
                                          "return 0;", "}"};
  auto realLines = s2.GetLines();
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(expectLines[i], realLines[i]);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}