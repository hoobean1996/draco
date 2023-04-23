#pragma once

#include <string>
#include <vector>
namespace draco {
namespace graphql {
// Source represents the input string to the GraphQL Server.
// In most cases, should be non-controll ASCII.
// By right, should support UTF-8.
class Source {
public:
  Source() = default;
  Source(std::string filename, std::string source);
  Source(const Source &source);
  Source(Source &&source);
  Source &operator=(const Source &source);
  ~Source();

  int GetSize() const;
  std::string GetFilename() const;
  std::string GetContent() const;
  void PrepareLines();
  std::vector<std::string> GetLines() const;
  int GetLineCount() const;

private:
  std::string filename_;
  std::string content_;
  std::vector<std::string> lines_;

  std::vector<std::string> split(const char delim);
};
} // namespace graphql
} // namespace draco