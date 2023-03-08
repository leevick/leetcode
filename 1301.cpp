#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 *
 *             i
 *             ^
 *             |
 *             |
 *             |
 *             |
 * j <-------- 0
 */

class Solution {
 public:
  static inline int boardToInt(vector<string> &board, int i, int j) {
    const auto &ch = board[i][j];
    const int ret = ch == 'S'   ? 0
                    : ch == 'E' ? 0
                    : ch == 'X' ? -10e5
                                : ch - '0';

    // cout << i << "," << j << "=" << ret << endl;
    return ret;
  }

  vector<int> pathsWithMaxScore(vector<string> &board) {
    const int M = board.size();
    const int N = board[0].size();

    auto dpScore = vector<vector<int>>(M, vector<int>(N, 0));
    auto dpPaths = vector<vector<int>>(M, vector<int>(N, 0));

    for (auto i = 0; i < M; i++) {
      for (auto j = 0; j < N; j++) {
        if (i == 0 && j == 0) {
          dpPaths[0][0] = 1;
          continue;
        }

        int lm = -10e5;
        int pa = 0;

        if (j - 1 >= 0) {
          lm = max(lm, boardToInt(board, M - 1 - i, N - 1 - j + 1) +
                           dpScore[i][j - 1]);
        }

        if (i - 1 >= 0) {
          lm = max(lm, boardToInt(board, M - 1 - i + 1, N - 1 - j) +
                           dpScore[i - 1][j]);
        }

        if (i - 1 >= 0 && j - 1 >= 0) {
          lm = max(lm, boardToInt(board, M - 1 - i + 1, N - 1 - j + 1) +
                           dpScore[i - 1][j - 1]);
        }

        dpScore[i][j] = lm >= 0 ? lm : -10e5;
        // cout << "dp(" << i << "," << j << ") = " << dpScore[i][j] << endl;

        if (dpScore[i][j] >= 0) {
          if (j - 1 >= 0) {
            if (dpScore[i][j] == boardToInt(board, M - 1 - i, N - 1 - j + 1) +
                                     dpScore[i][j - 1]) {
              pa = (pa + dpPaths[i][j - 1]) % (1000000000 + 7);
            }
          }

          if (i - 1 >= 0) {
            if (dpScore[i][j] == boardToInt(board, M - 1 - i + 1, N - 1 - j) +
                                     dpScore[i - 1][j]) {
              pa = (pa + dpPaths[i - 1][j]) % (1000000000 + 7);
            }
          }

          if (i - 1 >= 0 && j - 1 >= 0) {
            if (dpScore[i][j] ==
                boardToInt(board, M - 1 - i + 1, N - 1 - j + 1) +
                    dpScore[i - 1][j - 1]) {
              pa = (pa + dpPaths[i - 1][j - 1]) % (1000000000 + 7);
            }
          }
        }
        dpPaths[i][j] = pa;
      }
    }

    return {dpScore[M - 1][N - 1] > 0 ? dpScore[M - 1][N - 1] : 0,
            dpPaths[M - 1][N - 1]};
  }
};

int main(int argc, char const *argv[]) {
  auto sol = new Solution();

  vector<string> testCases[] = {{"E23", "2X2", "12S"}, {"EX", "XS"}};
  for (auto t : testCases) {
    auto ret = sol->pathsWithMaxScore(t);
    cout << ret[0] << "," << ret[1] << endl;
  }

  delete sol;

  return 0;
}
