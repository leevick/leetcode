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

class Solution
{
public:
    static inline int boardToInt(vector<string> &board, int i, int j) {

        const auto &ch = board[i][j];
        const int ret = ch == 'S' ? 0 : ch == 'E' ? 0
                                    : ch == 'X'   ? -10e5
                                                  : ch - '0';

        cout << i << "," << j << "=" << ret << endl;
        return ret;
    }

    vector<int> pathsWithMaxScore(vector<string> &board) {
        int dpScore[3][3] = {0};

        for (auto i = 0; i < 3; i++) {
            for (auto j = 0; j < 3; j++) {
                if (i == 0 && j == 0) {
                    dpScore[0][0] = 0;
                    continue;
                }

                int lm = -10e5;

                if (j - 1 >= 0) {
                    lm = max(lm, boardToInt(board, 2 - i, 2 - j + 1) + dpScore[i][j - 1]);
                }

                if (i - 1 >= 0) {
                    lm = max(lm, boardToInt(board, 2 - i + 1, 2 - j) + dpScore[i - 1][j]);
                }

                if (i - 1 > 0 && j - 1 > 0) {
                    lm = max(lm, boardToInt(board, 2 - i + 1, 2 - j + 1) + dpScore[i - 1][j - 1]);
                }

                dpScore[i][j] = lm >= 0 ? lm : -10e5;
                cout << "dp(" << i << "," << j << ") = " << dpScore[i][j] << endl;
            }
        }

        return {dpScore[2][2] > 0 ? dpScore[2][2] : 0, 0};
    }
};

int main(int argc, char const *argv[]) {
    auto sol = new Solution();

    vector<string> testCases[] = {{"E23", "2X2", "12S"}};
    for (auto t : testCases) {
        auto ret = sol->pathsWithMaxScore(t);
        cout << ret[0] << "," << ret[1] << endl;
    }

    delete sol;

    return 0;
}
