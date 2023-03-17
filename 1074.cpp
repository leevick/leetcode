#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ret = 0;
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum[i + 1][j + 1] = matrix[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
            }
        }

        unordered_map<int, int> hash;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j <= m; ++j) {
                hash.clear();
                hash.insert({0, 1});
                for (int k = 0; k < n; ++k) {
                    int s = sum[j][k + 1] - sum[i][k + 1];
                    ret += hash.find(s - target) == hash.end() ? 0 : hash[s - target];
                    hash[s]++;
                }
            }
        }

        return ret;
    }
};