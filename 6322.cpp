#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  bool checkValidGrid(vector<vector<int>>& grid) {
    struct helper {
      int r = 0;
      int c = 0;
      int step = 0;
      bool operator<(const helper& b) { return this->step < b.step; }
    };

    vector<helper> arr;
    int m = grid.size(), n = grid[0].size();

    if (grid[0][0] != 0) return false;

    for (auto i = 0; i < m; ++i)
      for (auto j = 0; j < n; ++j) {
        arr.push_back({i, j, grid[i][j]});
      }

    sort(arr.begin(), arr.end());

    vector<pair<int, int>> valid = {{1, 2}, {1, -2}, {-1, -2}, {-1, 2},
                                    {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};

    for (int i = 1; i < m * n; ++i) {
      bool found = false;
      for (auto v : valid) {
        if (v.first == (arr[i].r - arr[i - 1].r) &&
            v.second == (arr[i].c - arr[i - 1].c)) {
          found = true;
          break;
        }
      }

      if (found == false) return false;
    }

    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  //   vector<vector<int>> v = {{0, 11, 16, 5, 20},
  //                            {17, 4, 19, 10, 15},
  //                            {12, 1, 8, 21, 6},
  //                            {3, 18, 23, 14, 9},
  //                            {24, 13, 2, 7, 22}};

  vector<vector<int>> v = {{24, 11, 22, 17, 4},
                           {21, 16, 5, 12, 9},
                           {6, 23, 10, 3, 18},
                           {15, 20, 1, 8, 13},
                           {0, 7, 14, 19, 2}};
  cout << s.checkValidGrid(v) << endl;
  return 0;
}
