#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();
    vector<long long> ret(m, 0);
    for (auto i = 0; i < n; ++i) {
      for (auto j = 0; j < m; ++j) {
        ret[j] += nums[i] - queries[j] > 0 ? nums[i] - queries[j]
                                           : queries[j] - nums[i];
      }
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> n1 = {3, 1, 6, 8}, n2 = {2, 9, 6, 3}, n3 = {};
  vector<int> q1 = {1, 5}, q2 = {10}, q3 = {};

  auto ret = s.minOperations(n2, q2);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
