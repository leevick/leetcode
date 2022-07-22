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
      if (b.at(i) == a.at(i)) {
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
    auto dp = vector<vector<int>>(N, vector<int>(N, 0));
    auto link = vector<int>(N - 1, -1);

    int longest = 0;
    for (int i = 0; i < N - 1; i++) {
      dp[i][i] = 1;
      for (int j = i + 1; j < N; j++) {
        if (dp[i][j - 1] == -1) {
          break;
        } else {
          if (dp[i][j - 1] + N - j <= longest) {
            break;
          } else {
            if (link[j] == 1) {
              dp[i][j] = dp[i][j - 1] + 1;
              if (dp[i][j] > longest) {
                longest = dp[i][j];
              }
              continue;
            } else if (link[j] == 0) {
              dp[i][j] = -1;
              break;
            } else {
              auto r = isLinked(words[j - 1], words[j]);
              if (r) {
                link[j] = 1;
                dp[i][j] = dp[i][j - 1] + 1;
                if (dp[i][j] > longest) {
                  longest = dp[i][j];
                  cout << "(" << i << "," << j << ") = " << longest << endl;
                }
              } else {
                link[j] = 0;
                dp[i][j] = -1;
                break;
              }
            }
          }
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
