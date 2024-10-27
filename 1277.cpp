#include "leetcode.hpp"

class Solution {
 public:
  int countSquares(vector<vector<int>>& matrix) {
    auto m = matrix.size(), n = matrix[0].size();
    int sum = 0;
    auto dp = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0) {
          dp[i][j] = matrix[i][j];
        } else {
          if (matrix[i][j] == 0) {
            dp[i][j] = 0;
          } else {
            // transfer function
            /**
             *   consider this case
             *
             *   dp[i - 1][j - 1] = 5
             *   dp[i - 1][j]     = 2
             *   dp[i][j - 1]     = 3
             *
             *    --------------------> j
             *   |  1  1  1  1  1
             *   |  1  1  1  1  1
             *   |  1  1  1  1  1
             *   |  1  1  1  1  1  1
             *   |  1  1  1  1  1  1
             *   ↓        1  1  1  ?
             *   i
             */

            dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
          }
        }
        sum += dp[i][j];
      }
    }
    return sum;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> t1 =
                          {
                              {0, 1, 1, 1},
                              {1, 1, 1, 1},
                              {0, 1, 1, 1},
                          },

                      t2 =
                          {
                              {1, 0, 1},
                              {1, 1, 0},
                              {1, 1, 0},
                          },

                      t3 = {{0, 0, 0},
                            {0, 1, 0},
                            {0, 1, 0},
                            {1, 1, 1},
                            {1, 1, 0}};

  auto ret = s.countSquares(t1);  // 15
  ret = s.countSquares(t2);       // 7
  ret = s.countSquares(t3);       // 8
  return 0;
}
