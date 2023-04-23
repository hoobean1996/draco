#pragma once
#include "source.h"
#include "token.h"

namespace draco {
namespace graphql {
// Lexer lexes a GraphQL Source according to the GraphQL Grammar.
class Lexer {
public:
  explicit Lexer(const Source &source);
  Lexer(Lexer &&lexer);

  Lexer() = delete;
  Lexer(const Lexer &lexer) = delete;
  Lexer &operator=(const Lexer &lexer) = delete;
  ~Lexer();

  Token GetNextToken();
  Token PeekNextToken();

  // AdvanceOne is used to move forward for 1 character
  void AdvanceOne();

  int GetCurrentPosition();
  char GetCurrentChar();
  int GetNextPosition();

  // [Debug Only]
private:
  Source source_;
  int currentPosition_; // current index
  char currentChar_;    // current character
  int nextPosition_;    // next index after current index
};
} // namespace graphql
} // namespace draco