#include "leecode.hpp"

class Solution
{
public:
    void moveZeroes(vector<int> &nums) {
        int p = 0, r = nums.size();
        while (nums[--r] == 0 && r > 0)
            ;

        while (p != r) {
            if (nums[p] == 0) {
                nums.push_back(nums[p]);
                nums.erase(next(nums.begin(), p));
                r--;
            } else {
                p++;
            }
        }
        return;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> t1 = {0, 1, 0, 3, 12};
    s.moveZeroes(t1);
    for (auto i : t1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
