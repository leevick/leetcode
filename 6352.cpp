
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    int sub = nums[0], n = nums.size();
    set<int> indexes;

    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] - nums[j] == -k || nums[i] - nums[j] == k) {
          indexes.insert(i);
          indexes.insert(j);
        }
      }

    int ret = ((1 << indexes.size()) - 1 - indexes.size());
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> v = {2, 4, 6};
  s.beautifulSubsets(v, 2);
  return 0;
}