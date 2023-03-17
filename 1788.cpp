#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    struct range
    {
        int value;
        int start;
        mutable int end;
        mutable int sum;
        bool operator<(const range &b) {
            return this->sum > b.sum;
        }

        bool operator==(int b) {
            return this->value == b;
        }
    };

    int maximumBeauty(vector<int> &flowers) {
        int n = flowers.size();
        vector<range> ranges;
        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            int beauty = flowers[i];
            sum[i + 1] = sum[i] + beauty;
            auto r = find(ranges.begin(), ranges.end(), beauty);
            if (r == ranges.end()) {
                ranges.push_back({beauty, i, -1});
            } else {
                r->end = i;
                r->sum = sum[i + 1] - sum[r->start];
            }
        }

        sort(ranges.begin(), ranges.end());

        int mx = INT_MIN;
        for (auto r : ranges) {
            if (r.end == -1)
                continue;
            int local = r.sum;
            for (auto i = r.start + 1; i <= r.end - 1; ++i) {
                if (flowers[i] < 0) {
                    local = local - flowers[i];
                }
            }
            mx = max(local, mx);
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
