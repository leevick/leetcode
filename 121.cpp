
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lp = numeric_limits<int>::max();
        int profit = numeric_limits<int>::min();

        for (int i = 0; i < prices.size(); i++)
        {
            if (lp > prices[i])
            {
                lp = prices[i];
            }

            if (profit < prices[i] - lp)
            {
                profit = prices[i] - lp;
            }
        }
        return profit;
    }
};

int main(int argc, char const *argv[])
{
    auto s = new Solution();
    vector<int> a = {7, 1, 5, 3, 6, 4};
    s->maxProfit(a);
    return 0;
}
