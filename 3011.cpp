#include "leetcode.hpp"

class Solution {
 public:
  int countBits(int num) {
    static const int map[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    return map[num & 0xf] + (num > 0xf ? countBits(num >> 4) : 0);
  }
  bool canSortArray(vector<int>& nums) {
    vector<int> hash(9, -1);
    vector<int> mn(9, INT_MAX);

    const int n = nums.size();
    if (n == 1) return true;

    int mx = nums[0];
    for (int i = 1; i < n; ++i) {
      int m = countBits(nums[i - 1]);
      int n = countBits(nums[i]);
      if (m != n) {
        if (hash[n] == -1) {
          if (nums[i] < mx) return false;
          hash[n] = mx;
          mn[n] = nums[i];
        }
      }

      mn[n] = min(mn[n], nums[i]);
      if (mn[n] < hash[n]) return false;

      mx = max(mx, nums[i]);
    }

    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> t1 = {8, 4, 2, 30, 15}, t2 = {1, 2, 3, 4, 5},
              t3 = {3, 16, 8, 4, 2}, t4 = {89, 255, 255};
  auto ret = s.canSortArray(t1);
  ret = s.canSortArray(t2);
  ret = s.canSortArray(t3);
  ret = s.canSortArray(t4);
  return 0;
}
