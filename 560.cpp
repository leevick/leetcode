#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size(), sum = 0, ret = 0;
        unordered_map<int, int> hash = {{0, 1}};

        for (int i = 0; i < n; ++i) {
            sum = sum + nums[i];
            ret += hash.find(sum - k) == hash.end() ? 0 : hash[sum - k];
            hash[sum]++;
        }

        return ret;
    }
};