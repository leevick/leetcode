#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> getModifiedArray(int n, vector<vector<int>> &range) {
        vector<int> sum(n, 0);
        vector<int> diff(n + 1, 0);

        for (auto i : range) {
            diff[i[0]] += i[2];
            diff[i[1] + 1] -= i[2];
        }

        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc += diff[i];
            sum[i] = acc;
        }

        return sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> v = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    s.getModifiedArray(5, v);
    return 0;
}
