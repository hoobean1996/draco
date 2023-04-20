#pragma once
#include <cstdint>
#include <vector>

using std::vector;
namespace draco {
class SparseSet {
public:
  SparseSet();
  SparseSet(int cap);
  ~SparseSet();

  void Add(uint32_t x);
  bool Has(uint32_t x);

private:
  const int kDefaultCap_ = 10000;
  int cap_;
  vector<uint32_t> dense_;
  vector<uint32_t> sparse_;
};
} // namespace draco