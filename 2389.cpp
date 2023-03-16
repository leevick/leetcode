#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &num, vector<int> &q) {
        int n = num.size(), m = q.size();

        sort(num.begin(), num.end());

        vector<int> prefix(n + 1, 0), ret(m, 0);

        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + num[i];
        }

        for (int k = 0; k < m; k++) {

            if (q[k] >= prefix[n]) {
                ret[k] = n;
                continue;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = i; j <= n; ++j) {
                    if (prefix[j] - prefix[i] > q[k])
                        break;

                    if (ret[k] < j - i) {
                        ret[k] = j - i;
                    }
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {736411, 184882, 914641, 37925, 214915}, queries = {718089, 665450};

    s.answerQueries(nums, queries);

    return 0;
}
