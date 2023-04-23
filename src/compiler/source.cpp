#include "../../include/compiler/source.h"
#include <folly/String.h>
#include <sstream>

namespace draco {
namespace graphql {
Source::Source(std::string filename, std::string content)
    : filename_(filename), content_(content) {}
Source::~Source() {}
Source::Source(const Source &source) {
  filename_ = source.filename_;
  content_ = source.content_;
}
Source::Source(Source &&source) {
  filename_ = std::move(source.filename_);
  content_ = std::move(source.content_);
}
Source &Source::operator=(const Source &source) {
  if (this != &source) {
    this->filename_ = source.filename_;
    this->content_ = source.content_;
  }
  return *this;
}
int Source::GetSize() const { return content_.size(); }
std::string Source::GetFilename() const { return filename_; }
std::string Source::GetContent() const { return content_; }
void Source::PrepareLines() { lines_ = split('\n'); }

std::vector<std::string> Source::GetLines() const { return lines_; }
int Source::GetLineCount() const { return lines_.size(); }

std::vector<std::string> Source::split(const char delim) {
  std::vector<std::string> ans;
  folly::split(delim, content_, ans);
  for (auto &l : ans) {
    l = folly::trimWhitespace(l);
  }
  return ans;
}
} // namespace graphql
} // namespace draco