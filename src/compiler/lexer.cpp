#include "../../include/compiler/lexer.h"

namespace draco {
namespace graphql {
Lexer::Lexer(const Source &source)
    : source_(source), currentChar_('\0'), currentPosition_(-1),
      nextPosition_(0) {}
Lexer::Lexer(Lexer &&lexer) {
  currentPosition_ = std::move(lexer.currentPosition_);
  currentChar_ = std::move(lexer.currentChar_);
  nextPosition_ = std::move(lexer.nextPosition_);
  source_ = std::move(lexer.source_);
}
Lexer::~Lexer() {}

char Lexer::GetCurrentChar() { return currentChar_; }
int Lexer::GetCurrentPosition() { return currentPosition_; }
int Lexer::GetNextPosition() { return nextPosition_; }

Token Lexer::GetNextToken() {
  if (currentPosition_ == source_.GetSize()) {
    return Token();
  }
  return Token();
}

Token Lexer::PeekNextToken() {
  if (currentPosition_ == source_.GetSize()) {
    return Token();
  }
  return Token();
}

void Lexer::AdvanceOne() {
  if (nextPosition_ >= source_.GetSize()) {
    currentChar_ = '\0';
  } else {
    currentChar_ = source_.GetContent()[nextPosition_];
  }
  currentPosition_ = nextPosition_;
  nextPosition_++;
}

} // namespace graphql
} // namespace draco