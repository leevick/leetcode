#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minStartValue(vector<int> &nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            mn = min(sum, mn);
        }
        return 1 - mn < 1 ? 1 : 1 - mn;
    }
};