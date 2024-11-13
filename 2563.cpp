#include "leetcode.hpp"

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long ret = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > upper) --j;
      ret += j - i;
    }

    for (int i = 0, j = nums.size() - 1; i < j; ++i) {
      while (i < j && nums[i] + nums[j] > lower - 1) --j;
      ret -= j - i;
    }
    return ret;
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> t1 = {0, 1, 7, 4, 4, 5};
  s.countFairPairs(t1, 3, 6);
  return 0;
}
