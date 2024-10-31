#include "leetcode.hpp"

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    const int n = nums.size();
    auto dp = vector<int>(n, 1);
    int mx = 1;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] > nums[i] && dp[j] < dp[i] + 1) {
          dp[j] = dp[i] + 1;
          mx = max(dp[j], mx);
        }
      }
    }
    return mx;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  auto tc = vector<vector<int>>{
      {4, 10, 4, 3, 8, 9},
  };

  for (auto t : tc) {
    s.lengthOfLIS(t);
  }

  return 0;
}
