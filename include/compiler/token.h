#pragma once
#include <string>
namespace draco {
namespace graphql {
enum TokenKind {
  ILLEGAL,
  UNICODE_BOM,

  // Scalar Literal
  INTEGER,
  FLOAT,
  STRING,
  BOOLEAN,
  ENUM,

  // Name
  // - Identifier
  // - Keyword
  ID,
  KEYWORD,

  // Pubctuation
  OPENING_BRACE,
  CLOSING_BRACE,
  OPENING_PARENTHESIS,
  CLOSING_PARENTHESIS,
  COLON,
  COMMA,
  // Directive
  DIRECTIVE,

  // Comment,
  COMMENT,
};

class Token {
public:
  Token();
  Token(const TokenKind &kind, std::string value, int row, int col);
  ~Token();

  TokenKind GetTokenKind();
  std::string GetValue();
  std::pair<int, int> GetPosition();

private:
  TokenKind kind_;
  std::string value_;
  int row_;
  int col_;
};
} // namespace graphql

} // namespace draco