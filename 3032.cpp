#include "leetcode.hpp"

class Solution {
 public:
  int numberCount(int a, int b) {
    int sum = 0;
    for (auto i = a; i <= b; ++i) {
      int digits[10] = {0};
      string s = to_string(i);
      for (int j = 0; j < s.size(); ++j) {
        if (digits[s[j] - '0'] != 0) {
          sum++;
          break;
        } else {
          digits[s[j] - '0'] = 1;
        }
      }
    }
    return b - a + 1 - sum;
  }
};

int main(int argc, char const *argv[]) {
  /**
  Example 1:
  Input: a = 1, b = 20
  Output: 19
  Explanation: All the numbers in the range [1, 20] have unique digits
  except 11. Hence, the answer is 19.

  Example 2:

  Input: a = 9, b = 19
  Output: 10
  Explanation: All the numbers in the range [9, 19] have unique digits
  except 11. Hence, the answer is 10.

  Example 3:

  Input: a = 80, b = 120
  Output: 27
  Explanation: There are 41 numbers in the range [80, 120], 27 of which have
  unique digits.
  **/

  Solution s;
  auto ret = s.numberCount(1, 20);
  ret = s.numberCount(9, 19);
  ret = s.numberCount(80, 120);

  return 0;
}
