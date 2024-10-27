#include "leetcode.hpp"

class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    auto hash = vector<unsigned long long>(26, 0);
    unsigned long long ret = 0;

    for (auto c : s) {
      hash[c - 'a']++;
    }
    for (; t > 0; t--) {
      rotate(hash.begin(), hash.end() - 1, hash.end());
      hash[1] = (hash[1] + hash[0]) % 1000000007;
    }

    for (auto h : hash) {
      ret = (ret + h) % 1000000007;
    }
    return ret % 1000000007;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  auto ret = s.lengthAfterTransformations("abcyy", 2);
  ret = s.lengthAfterTransformations("azbk", 1);
  ret =
      s.lengthAfterTransformations("jqktcurgdvlibczdsvnsg", 7517);  // 79033769
  return 0;
}
