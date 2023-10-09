#include <leecode.hpp>

class Solution
{
public:
    int removeElement(vector<int> &nums, int val) {
        auto i = nums.begin();
        auto n = nums.size();
        while (i != nums.end()) {
            if (*i == val) {
                i = nums.erase(i);
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};