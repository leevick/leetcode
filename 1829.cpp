#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
        int n = nums.size();
        int acc = nums[0];
        const int mask = (1 << maximumBit) - 1;
        vector<int> ret(n, 0);
        for (int i = 0; i < n; ++i) {
            acc ^= i > 0 ? nums[i] : 0;
            ret[n - 1 - i] = mask ^ acc;
        }
        return ret;
    }
};