#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> ret;
    unordered_map<int, int> hash;
    unordered_set<int> collect;
    for (auto nu : nums) {
      hash[nu] = hash[nu] + 1;
      collect.insert(nu);
    }

    while (!collect.empty()) {
      vector<int> row;
      for (auto i = hash.begin(); i != hash.end(); ++i) {
        if (i->second == 0) {
          continue;
        } else {
          row.push_back(i->first);
          i->second = i->second - 1;
          if (i->second == 0) {
            collect.erase(i->first);
          }
        }
      }
      ret.push_back(row);
    }

    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> v1 = {1, 3, 4, 1, 2, 3, 1};
  vector<int> v2 = {1, 2, 3, 4};
  auto res1 = s.findMatrix(v1);
  for (auto r : res1) {
    for (auto c : r) {
      cout << c << " ";
    }
    cout << endl;
  }

  auto res2 = s.findMatrix(v2);
  for (auto r : res2) {
    for (auto c : r) {
      cout << c << " ";
    }
    cout << endl;
  }
  return 0;
}
