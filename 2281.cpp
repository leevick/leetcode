#include <vector>

using namespace std;

class Solution
{
public:
    int totalStrength(vector<int> &strength) {
        const int N = strength.size();
        vector<vector<int>> dpMin(N, vector<int>(N, 1000000007));
        vector<vector<int>> dpSum(N, vector<int>(N, 0));

        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                const int sij = strength[j];
                if (j == i) {
                    dpSum[i][j] = sij;
                    dpMin[i][j] = sij;
                    sum = (sum + sij * sij) % 1000000007;
                    // printf("%d,%d sum = %d min = %d total = %d\n",i,j,sij,sij,sum);
                    continue;
                }

                if (sij < dpMin[i][j - 1]) {
                    dpMin[i][j] = sij;
                } else {
                    dpMin[i][j] = dpMin[i][j - 1];
                }

                dpSum[i][j] = dpSum[i][j - 1] + sij;

                sum = (sum + dpSum[i][j] * dpMin[i][j]) % 1000000007;
                // printf("%d,%d sum = %d min = %d total = %d\n",i,j,dpSum[i][j],dpMin[i][j],sum);
            }
        }

        return sum;
    }
};