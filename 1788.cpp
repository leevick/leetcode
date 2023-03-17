#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int> &flowers) {
        int n = flowers.size();
        unordered_map<int, int> hash;
        int mx = INT_MIN, sum = 0;

        for (int i = 0; i < n; ++i) {
            int beauty = flowers[i];
            mx = hash.find(beauty) == hash.end() ? mx : max(mx, sum - hash[beauty] + 2 * beauty);
            sum += beauty > 0 ? beauty : 0;
            if (hash.find(beauty) == hash.end()) {
                hash[beauty] = sum;
            }
        }

        return mx;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> flowers = {-1, -2, 0, -1};
    cout << s.maximumBeauty(flowers) << endl;
    return 0;
}
