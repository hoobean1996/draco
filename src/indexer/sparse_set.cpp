#include "sparse_set.h"

namespace draco {
SparseSet::SparseSet()
    : cap_(kDefaultCap_), dense_(vector<uint32_t>(cap_, 0)),
      sparse_(vector<uint32_t>(cap_, 0)) {}

SparseSet::SparseSet(int cap)
    : cap_(cap), dense_(vector<uint32_t>(cap_, 0)),
      sparse_(vector<uint32_t>(cap_, 0)) {}

SparseSet::~SparseSet() {
  dense_.clear();
  dense_.shrink_to_fit();
  sparse_.clear();
  sparse_.shrink_to_fit();
}

void SparseSet::Add(uint32_t x) {
  auto v = sparse_[x];
  if (v < dense_.size() && dense_[v] == x) {
    return;
  }
  auto n = dense_.size();
  sparse_[x] = n;
  dense_.push_back(x);
}

bool SparseSet::Has(uint32_t x) {
  auto v = sparse_[x];
  return v < dense_.size() && dense_[v] == x;
}
} // namespace draco