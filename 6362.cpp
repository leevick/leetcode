#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int n = s.size();
    int mx = 0, zsum = 0, osum = 0;
    int state = 0;

    for (int i = 0; i < n; ++i) {
      switch (state) {
        case 0: {
          if (s[i] == '0') {
            state = 1;
            zsum++;
          }
        } break;
        case 1: {
          if (s[i] == '0') {
            zsum++;
          } else {
            state = 2;
            osum++;
            if (osum == zsum) {
              mx = max(mx, 2 * osum);
            }
          }
        } break;
        case 2: {
          if (s[i] == '0') {
            zsum = 1;
            osum = 0;
            state = 1;
          } else {
            osum++;
            if (osum == zsum) {
              mx = max(mx, 2 * osum);
            }
          }
        } break;
      }
    }

    return mx;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  cout << s.findTheLongestBalancedSubstring("01000111") << endl;
  cout << s.findTheLongestBalancedSubstring("00111") << endl;
  cout << s.findTheLongestBalancedSubstring("111") << endl;
  cout << s.findTheLongestBalancedSubstring("01") << endl;

  return 0;
}
