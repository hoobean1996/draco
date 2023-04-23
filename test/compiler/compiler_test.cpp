#include "../../include/compiler/lexer.h"
#include "../../include/compiler/source.h"
#include "../../include/compiler/token.h"
#include <gtest/gtest.h>

class CompilerTest : public ::testing::Test {

protected:
  void SetUp() override {
    sourceCode_ = R"(#include <iostream>
int main(int argc, char** argv) {
  return 0;
})";
    source_ = draco::graphql::Source("main.cpp", sourceCode_);
    lexer_ = new draco::graphql::Lexer(source_);
  }

  std::string sourceCode_;
  draco::graphql::Source source_;
  draco::graphql::Lexer *lexer_;
};

TEST_F(CompilerTest, Token) {
  using draco::graphql::Token;
  Token t;
  EXPECT_EQ(t.GetTokenKind(), draco::graphql::ILLEGAL);
  Token t2(draco::graphql::INTEGER, "3", 0, 0);
  EXPECT_EQ(t2.GetTokenKind(), draco::graphql::INTEGER);
  EXPECT_EQ(t2.GetValue(), "3");
  EXPECT_EQ(t2.GetPosition(), std::make_pair(0, 0));
}

TEST_F(CompilerTest, Source) {
  using draco::graphql::Source;
  Source s;
  EXPECT_EQ(s.GetSize(), 0);

  EXPECT_EQ(source_.GetFilename(), "main.cpp");
  EXPECT_EQ(source_.GetSize(), sourceCode_.size());
  EXPECT_EQ(source_.GetContent(), sourceCode_);
  source_.PrepareLines();
  EXPECT_EQ(source_.GetLineCount(), 4);
  std::vector<std::string> expectLines = {"#include <iostream>",
                                          "int main(int argc, char** argv) {",
                                          "return 0;", "}"};
  auto realLines = source_.GetLines();
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(expectLines[i], realLines[i]);
  }
}

TEST_F(CompilerTest, Lexer) {
  using draco::graphql::Lexer;
  Lexer l(source_);
  EXPECT_EQ(l.GetCurrentChar(), '\0');
  EXPECT_EQ(l.GetCurrentPosition(), -1);
  EXPECT_EQ(l.GetNextPosition(), 0);
  l.AdvanceOne();
  for (int i = 0; i < source_.GetSize(); i++) {
    EXPECT_EQ(l.GetCurrentChar(), sourceCode_[i]);
    l.AdvanceOne();
  }
  EXPECT_EQ(l.GetCurrentChar(), '\0');
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}