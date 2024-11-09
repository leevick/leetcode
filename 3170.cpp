#include "leetcode.hpp"

bool compare(pair<char, int> a, pair<char, int> b) {
  if (a.first > b.first) {
    return true;
  } else if (a.first == b.first) {
    return a.second < b.second;
  } else {
    return false;
  }
}

class Solution {
 public:
  string clearStars(string s) {
    string ret = "";
    priority_queue<pair<char, int>, vector<pair<char, int>>,
                   function<bool(pair<char, int>, pair<char, int>)>>
        q(compare);

    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '*') {
        if (!q.empty()) {
          q.pop();
        }
      } else {
        q.push(make_pair(s[i], i));
      }
    }

    vector<pair<int, char>> res;
    while (!q.empty()) {
      res.push_back(make_pair(q.top().second, q.top().first));
      q.pop();
    }

    sort(res.begin(), res.end());
    for (auto p : res) {
      ret += p.second;
    }

    return ret;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string t1 = "dk**";
  string t2 = "aaba*";
  string t3 = "de*";
  s.clearStars(t3);
  s.clearStars(t2);
  s.clearStars(t1);
  return 0;
}
