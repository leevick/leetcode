#include <string>

using namespace std;

class Solution {
 public:
  int balancedStringSplit(string s) {
    int st = 0, ct = 0, l = 0, r = 0;
    for (st = 0; st < s.size(); st++) {
      s[st] == 'L' ? l++ : r++;
      if (l == r && l != 0) {
        ct++;
        l = 0;
        r = 0;
      }
    }
    return ct;
  }
};
