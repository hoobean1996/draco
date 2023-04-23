#include "../../include/compiler/token.h"
#include <utility>

namespace draco {
namespace graphql {
Token::Token() : kind_(ILLEGAL) {}
Token::Token(const TokenKind &kind, std::string value, int row, int col)
    : kind_(kind), value_(value), row_(row), col_(col) {}

Token::~Token() {}
TokenKind Token::GetTokenKind() { return kind_; }
std::string Token::GetValue() { return value_; }
std::pair<int, int> Token::GetPosition() { return std::make_pair(row_, col_); }
} // namespace graphql
} // namespace draco
