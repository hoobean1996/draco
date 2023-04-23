#include "../../include/compiler/lexer.h"

namespace draco {
namespace graphql {
Lexer::Lexer(const Source &source) : source_(source) {}
Lexer::Lexer(Lexer &&lexer) { source_ = std::move(lexer.source_); }
Lexer::~Lexer() {}

Token Lexer::GetNextToken() {
  if (currentPosition_ == source_.GetSize()) {
  }
}

Token Lexer::PeekNextToken() {}
} // namespace graphql
} // namespace draco