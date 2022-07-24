#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  inline bool isLinked(string a, string b) {
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

  void dfs(int index, vector<bool>& visited, vector<vector<char>>& link,
           vector<string>& words, int depth, int& large) {
    // visited[index] = true;

    int d = depth + 1;
    if (d > large) {
      large = d;
    }

    visited[index] = true;

    for (auto i = 0; i < visited.size(); i++) {
      if (link[index][i] == 0) {
        visited[i] = true;
        continue;
      }

      if (link[index][i] == 1) {
        dfs(i, visited, link, words, d, large);
        continue;
      }

      if (link[index][i] == -1) {
        if (isLinked(words[index], words[i])) {
          link[index][i] = 1;
          dfs(i, visited, link, words, d, large);
          continue;
        } else {
          link[index][i] = 0;
          visited[i] = true;
          continue;
        }
      }
    }
  }

  int longestStrChain(vector<string>& words) {
    const int N = words.size();
    auto link = vector<vector<char>>(N, vector<char>(N, -1));
    int large = 0;

    for (int i = 0; i < N; i++) {
      auto visited = vector<bool>(N, false);
      dfs(i, visited, link, words, 0, large);
    }
    return large;
  }
};

int main(int argc, char const* argv[]) {
  auto sol = new Solution();

  vector<string> v = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
  auto ret = sol->longestStrChain(v);
  cout << ret << endl;
  return 0;
}
