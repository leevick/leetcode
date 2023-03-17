#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        for (int i = 0; i < n; ++i) {
            if (sum[i] == sum[n] - sum[i + 1])
                return i;
        }

        return -1;
    }
};