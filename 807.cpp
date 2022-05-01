#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> row_max(rows, 0);
    vector<int> col_max(cols, 0);

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] > row_max[i]) {
          row_max[i] = grid[i][j];
        }
        if (grid[i][j] > col_max[j]) {
          col_max[j] = grid[i][j];
        }
      }
    }

    int diff = 0;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        int lim = min(row_max[i], col_max[j]);
        if (grid[i][j] < lim) {
          diff += lim - grid[i][j];
        }
      }

    return diff;
  }
};