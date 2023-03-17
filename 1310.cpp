#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size(), m = queries.size();
        vector<int> x(n + 1, 0), ret;

        for (int i = 0; i < n; ++i) {
            x[i + 1] = x[i] ^ arr[i];
        }

        for (int i = 0; i < m; ++i) {
            ret.push_back(x[queries[i][1] + 1] ^ x[queries[i][0]]);
        }

        return ret;
    }
};