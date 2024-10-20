#include "leecode.hpp"

class Solution {
 public:
  vector<string> stringSequence(string target) {
    vector<string> ret;
    ret.push_back("a");
    while (ret.back() != target) {
      auto last = ret.back();
      auto len = last.length();
      if (target[len - 1] == last[len - 1]) {
        ret.push_back(last + "a");
      } else {
        last[len - 1] = last[len - 1] + 1;
        ret.push_back(last);
      }
    }
    return ret;
  }
};

int main(int argc, char const *argv[]) {
  string t1 = "abc", t2 = "he";
  Solution s;
  auto ret = s.stringSequence(t1);
  ret = s.stringSequence(t2);
  return 0;
}
