#include "leecode.hpp"

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        const int n = nums.size();
        int sum = 0, j = 0, len = INT32_MAX;
        for (auto i = 0; i < n; ++i) {
            sum += nums[i];
            while (sum >= target) {
                len = min(len, i - j + 1);
                sum -= nums[j++];
            }
        }
        return len == INT32_MAX ? 0 : len;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> t1 = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, t1) << endl;
    return 0;
}
