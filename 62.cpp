#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> paths(m, vector<int>(n, 0));
    paths[0][0] = 1;
    for (auto i = 1; i < m; i++) {
      paths[i][0] = 1;
    }
    for (auto j = 1; j < n; j++) {
      paths[0][j] = 1;
    }

    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++) {
        paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
      }
    return paths[m - 1][n - 1];
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int ret = s.uniquePaths(3, 3);
  return 0;
}
