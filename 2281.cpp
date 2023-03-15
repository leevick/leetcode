#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int totalStrength(vector<int> &A) {
        long long sum = 0, n = A.size(), ac = 0, mod = 1'000'000'007;
        vector<long long> stack = {}, acc(n + 2, 0);
        for (int r = 0; r <= n; ++r) {
            int a = r < n ? A[r] : 0;
            ac = (ac + a) % mod;
            acc[r + 1] = acc[r] + ac;
            // printf("[%d]a = %d ac = %d acc[%d] = %d\n", r, a, ac, r + 1, acc[r + 1]);
            while (!stack.empty() && A[stack.back()] > a) {
                int i = stack.back();
                stack.pop_back();
                int l = stack.empty() ? -1 : stack.back();

                long long lacc = l < 0 ? acc[i] : acc[i] - acc[l];
                long long racc = acc[r] - acc[i];
                int ln = i - l, rn = r - i;
                sum = (sum + (racc * ln - lacc * rn) % mod * A[i] % mod) % mod;
                // printf("[%d][%d][%d] lacc = %d racc = %d sum = %d\n", l, i, r, lacc, racc, sum);

                // printf("([%d]->%d,[%d]) ", i, A[i], l);
            }
            // printf("\n");
            stack.push_back(r);
        }
        return (sum + mod) % mod;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {1, 3, 1, 2};
    cout << s.totalStrength(v) << endl;
    return 0;
}
