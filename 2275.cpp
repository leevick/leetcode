#include "leetcode.hpp"

class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    vector<int> bits(24, 0);

    for (int i = 0; i < 24; ++i) {
      bool all_zero = true;
      for (auto j = candidates.begin(); j != candidates.end(); j++) {
        if (*j != 0) {
          bits[i] += *j % 2;
          *j = *j / 2;
          all_zero = false;
        }
      }
      if (all_zero) {
        break;
      }
    }
    return *max_element(bits.begin(), bits.end());
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> t1 = {16, 17, 71, 62, 12, 24, 14};
  auto ret = s.largestCombination(t1);
  return 0;
}
