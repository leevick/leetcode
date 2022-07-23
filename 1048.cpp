#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isLinked(string a, string b) {
    if (b.length() != a.length() + 1) return false;
    int i = 0, j = 0;
    for (i = 0, j = 0; i < a.length(); i++, j++) {
      if (b.at(j) == a.at(i)) {
        continue;
      } else {
        j++;
      }
      if (j - i >= 2) {
        return false;
      }
    }

    if (j - i >= 2) {
      return false;
    } else {
      return true;
    }
  }

  int longestStrChain(vector<string>& words) {
    const int N = words.size();
    auto dp = vector<vector<pair<int, int>>>(
        N, vector<pair<int, int>>(N, make_pair(0, 0)));

    int longest = 0;
    for (int i = 0; i < N - 1; i++) {
      dp[i][i].first = 1;
      dp[i][i].second = i;

      for (int j = i + 1; j < N; j++) {
        auto r = isLinked(words[dp[i][j - 1].second], words[j]);
        if (r) {
          dp[i][j].first = dp[i][j - 1].first + 1;
          dp[i][j].second = j;
          if (dp[i][j].first > longest) {
            longest = dp[i][j].first;
            cout << "(" << i << "," << j << ") = " << longest << endl;
          }
        } else {
          dp[i][j].first = dp[i][j - 1].first;
          dp[i][j].second = dp[i][j - 1].second;
        }
      }
    }
    return longest;
  }
};

int main(int argc, char const* argv[]) {
  auto sol = new Solution();

  vector<string> v = {"a", "b", "ba", "bca", "bda", "bdca"};
  auto ret = sol->longestStrChain(v);
  cout << ret << endl;
  return 0;
}
