#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
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
            // int mxi = 0;
            // int mni = 0;
            // int mxv = 0;
            // int mnv = N + 1;

            for (auto j = i; j < N; j++) {
                const int idx = s[j] - 'a';
                hash[idx] += 1;

                int mxv = 0;
                int mnv = N + 1;
                for (auto k = 0; k < 26; k++) {
                    if (hash[k] == 0)
                        continue;

                    if (hash[k] > mxv)
                        mxv = hash[k];

                    if (hash[k] < mnv)
                        mnv = hash[k];
                }

                span = max(span, mxv - mnv);

                /*

                if (hash[idx] < mnv) {
                    mni = 1;
                    mnv = hash[idx];
                } else if (hash[idx] == mnv) {
                    mni++;
                }

                if (hash[idx] > mxv) {
                    mxi = 1;
                    mxv = hash[idx];
                } else if (hash[idx] == mnv) {
                    mxi++;
                }

                // int sp = mxv - mnv;
                if (mxi > 0 && mni > 0) {
                    const int sp = mxi == 1 && mni == 1 ? 0 : mxv - mnv;
                    span = max(span, sp);
                    // cout << "sp = " << mxv - mnv << endl;
                }

                // printf("[%d] max:%d->%d min:%d->%d\n", j, mxi, mxv, mni, mnv);

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
                */
            }
        }

        return span;
    }
};

int main(int argc, char const *argv[]) {
    auto sol = new Solution();
    cout << sol->largestVariance(argv[1]) << endl;
    delete sol;
    return 0;
}
