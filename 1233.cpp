#include "leetcode.hpp"

class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> ret;
    sort(folder.begin(), folder.end());
    ret.push_back(folder.front());
    string last = ret.back();

    for (auto i = 1; i < folder.size(); ++i) {
      if (folder[i].substr(0, last.size()) == last &&
          folder[i][last.size()] == '/') {
        continue;
      } else {
        ret.push_back(folder[i]);
        last = ret.back();
      }
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<string>> t = {
      {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},
      {"/a", "/a/b/c", "/a/b/d"},
      {"/a/b/c", "/a/b/ca", "/a/b/d"},
      {"/ah/al/am", "/ah/al"},
  };

  for (auto tc : t) {
    auto ret = s.removeSubfolders(tc);
  }
  return 0;
}
