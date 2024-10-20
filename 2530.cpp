#include "leecode.hpp"

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        for (auto num : nums) {
            pq.push(num);
        }

        for (int i = 0; i < k; ++i) {
            int head = pq.top();
            sum += head;
            pq.pop();
            pq.push(head % 3 == 0 ? head / 3 : head / 3 + 1);
        }
        return sum;
    }
};