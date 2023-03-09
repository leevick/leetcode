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

        // short *dp = new short[N * N * 26]{0};

        int span = 0;

        for (auto i = 0; i < N; i++) {
            int hash[26] = {0};
            int mxi = -1;
            int mni = -1;
            int mxv = 0;
            int mnv = N + 1;

            for (auto j = i; j < N; j++) {
                const int idx = s[j] - 'a';
                hash[idx] += 1;

                if (hash[idx] < mnv) {
                    mnv = hash[idx];
                    mni = idx;
                } else if (idx == mni) {
                    mnv = hash[idx];
                }

                if (hash[idx] > mxv) {
                    mxv = hash[idx];
                    mxi = idx;
                } else if (idx == mxi) {
                    mxv = hash[idx];
                }

                // int sp = mxv - mnv;
                if (mxi >= 0 && mni >= 0) {
                    span = max(span, mxv - mnv);
                    // cout << "sp = " << mxv - mnv << endl;
                }

                // cout << i << "," << j << ","
                //      << idx << "," << hash[idx] << "," << mni << "," << mxi << "," << mnv << "," << mxv << endl;

                // int mn = N;
                // int mx = 0;
                // for (int k = 0; k < 26; k++) {
                //     const int v = dp[i * N * 26 + j * 26 + k];
                //     if (v > 0 && v < mn) {
                //         mn = v;
                //     }
                //     mx = max(mx, v);
                // }

                // span = max(span, mx - mn);
                // cout << "mx = " << mx << "mn = " << mn << " span = " << span << endl;
            }
        }

        return span;
    }
};

int main(int argc, char const *argv[]) {
    auto sol = new Solution();
    cout << sol->largestVariance("paa") << endl;
    // delete sol;
    return 0;
}
