#include "leetcode.hpp"

class Solution {
 public:
  int longestSquareStreak(vector<int>& nums) {
    map<unsigned long long, int> hash;
    sort(nums.begin(), nums.end());
    auto ut = unique(nums.begin(), nums.end());
    nums.resize(ut - nums.begin());

    int streak = -1;
    for (auto nn : nums) {
      unsigned long long n = nn;
      auto it = hash.find(n);
      if (it == hash.end()) {
        hash[n * n]++;
      } else {
        hash[n * n] = it->second + 1;
        if (it->second + 1 >= 2) {
          streak = max(streak, it->second + 1);
        }
        hash.erase(it);
      }
    }
    return streak;
  }
};

int main(int argc, char const* argv[]) {
  auto tc =
      vector<vector<int>>{{2, 4, 4, 2}, {4, 3, 6, 16, 8, 2}, {2, 3, 5, 6, 7}};
  Solution s;
  for (auto c : tc) {
    s.longestSquareStreak(c);
  }
  return 0;
}
