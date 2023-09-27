#include <iostream>

using namespace std;

class Solution {
 public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int sum = 0;
    if (k <= 0) return sum;
    if (k <= numOnes) return k;
    sum += numOnes;
    k -= numOnes;
    if (k <= numZeros) return sum;
    k -= numZeros;
    if (k <= numNegOnes) return sum - k;
    return sum - numNegOnes;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  cout << s.kItemsWithMaximumSum(3, 2, 0, 2) << endl;
  cout << s.kItemsWithMaximumSum(3, 2, 0, 4) << endl;
  return 0;
}
