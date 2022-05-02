#include <algorithm>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int sum = 0;
    int one = 2;
    int two = 1;

    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    for (int i = 2; i < n; i++) {
      sum = one + two;
      two = one;
      one = sum;
    }
    return sum;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  s.climbStairs(2);
  return 0;
}
