#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    long long maximumBooks(vector<int> &books) {
        const int N = books.size();
        // auto dp = vector<unsigned long>(N, 0);
        long long mx = 0;
        for (auto i = 0; i < N; i++) {

            long long sum = 0;
            for (int j = i; j < N; j++) {
                if (books[j] < books[i]) {
                    continue;
                } else {
                    sum += books[j];
                }
            }

            mx = max(mx, sum);

            /*
            if (i == 0) {
                dp[i] = books[i];
                continue;
            }

            if (books[i] <= books[i - 1]) {
                dp[i] = books[i];
            } else {
                dp[i] = dp[i - 1] + books[i];
            }

            mx = dp[i] > mx ? dp[i] : mx;
            */
        }
        return mx;
    }
};