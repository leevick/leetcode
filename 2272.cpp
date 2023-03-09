#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestVariance(string s) {

        const unsigned short N = s.size();

        short *dp = new short[N * N * 26]{0};

        int span = 0;

        for (auto i = 0; i < N; i++) {
            for (auto j = i; j < N; j++) {
                if (j == i) {
                    dp[i * N * 26 + j * 26 + s[j] - 'a'] = 1;
                } else {
                    for (auto k = 0; k < 26; k++) {
                        dp[i * N * 26 + j * 26 + k] = dp[i * N * 26 + (j - 1) * 26 + k] + (s[j] - 'a' == k ? 1 : 0);
                    }
                }

                int mn = N;
                int mx = 0;
                for (int k = 0; k < 26; k++) {
                    const int v = dp[i * N * 26 + j * 26 + k];
                    if (v > 0 && v < mn) {
                        mn = v;
                    }
                    mx = max(mx, v);
                }

                span = max(span, mx - mn);
                // cout << "mx = " << mx << "mn = " << mn << " span = " << span << endl;
            }
        }

        return span;
    }
};

int main(int argc, char const *argv[]) {
    auto sol = new Solution();
    cout << sol->largestVariance("aababbb") << endl;
    // delete sol;
    return 0;
}
