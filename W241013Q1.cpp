#include "leetcode.hpp"

struct helper {
  int value;
  int count;
  bool operator<(const helper& b) {
    return count < b.count || (count == b.count && value < b.value);
  }
};

class Solution {
 public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    vector<int> ret;
    const int n = nums.size();

    for (int i = 0; i < n - k + 1; ++i) {
      map<int, int> hash;
      for (int j = i; j < i + k; ++j) {
        hash[nums[j]]++;
      }
      vector<helper> v;
      for (auto p : hash) {
        v.push_back({p.first, p.second});
      }
      sort(v.begin(), v.end());
      int sum = 0;
      for (int j = 0; j < x && j < v.size(); ++j) {
        sum += v[v.size() - j - 1].value * v[v.size() - j - 1].count;
      }
      ret.push_back(sum);
    }

    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;

  vector<int> t1 = {1, 1, 2, 2, 3, 4, 2, 3};
  vector<int> t2 = {3, 8, 7, 8, 7, 5};
  vector<int> t3 = {9, 2, 2};
  //   auto r1 = s.findXSum(t1, 6, 2);
  //   auto r2 = s.findXSum(t2, 2, 2);
  auto r3 = s.findXSum(t3, 3, 3);

  return 0;
}
