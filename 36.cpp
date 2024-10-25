#include "leetcode.hpp"

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board) {

        auto rf = vector<vector<bool>>(9, vector<bool>(9, false));
        auto cf = vector<vector<bool>>(9, vector<bool>(9, false));
        auto gf = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));

        for (auto i = 0; i < 9; ++i) {
            for (auto j = 0; j < 9; ++j) {
                const char c = board[i][j];
                if (c == '.')
                    continue;

                if (rf[i][c - '1'])
                    return false;
                else
                    rf[i][c - '1'] = true;

                if (cf[j][c - '1'])
                    return false;
                else
                    cf[j][c - '1'] = true;

                if (gf[i / 3][j / 3][c - '1'])
                    return false;
                else
                    gf[i / 3][j / 3][c - '1'] = true;
            }
        }

        return true;
    }
};
