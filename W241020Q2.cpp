#include "leecode.hpp"

class Solution {
 public:
  int numberOfSubstrings(string s, int k) {
    int ret = 0;
    auto n = s.size();
    auto dp1 = vector<vector<map<char, int>>>(
        n, vector<map<char, int>>(n, map<char, int>()));
    // auto dp2 = vector<int>(n, -1);

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (i == j) {
          dp1[i][j][s[j] - 'a'] = 1;
          if (k == 1) {
            ret += n - j;
            break;
            // dp2[i] = j;
          }
        } else {
          //   if (dp2[i] != -1) {
          //     ret++;
          //   } else {
          dp1[i][j] = dp1[i][j - 1];
          if ((++dp1[i][j][s[j] - 'a']) >= k) {
            ret += n - j;
            break;
            // dp2[i] = j;
          }
          //   }
        }
      }
    }

    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.numberOfSubstrings("abacb", 2);
  ret = s.numberOfSubstrings("abcde", 1);
  return 0;
}
