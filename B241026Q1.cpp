#include "leetcode.hpp"

class Solution {
 public:
  int possibleStringCount(string word) {
    int n = word.size();
    if (n == 1) return 1;
    char current = word[0];
    int len = 1;
    int sum = 1;
    for (int i = 1; i <= word.size(); ++i) {
      if (i == word.size() || word[i] != current) {
        if (len > 1) {
          sum += len - 1;
        }
        current = word[i];
        len = 1;
      } else {
        len++;
      }
    }

    return sum;
  }
};

int main(int argc, char const *argv[]) {
  vector<string> cases = {"abbcccc", "abcd", "aaaa"};
  Solution s;
  for (auto c : cases) {
    s.possibleStringCount(c);
  }

  return 0;
}
