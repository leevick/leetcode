#include <vector>

using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<int> dp;
    int sum = 0;
    for (auto i = 0; i < query_row; i++) {
      // Fill
      if (i == 0) {
        dp.push_back(1);
        sum += 1;
      }

      // Judge
      if (poured < sum) {
        return 0.0;
      }
    }
  }
};