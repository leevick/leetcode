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

  void dfs(int index, set<int>& not_visited, vector<vector<char>>& link,
           vector<string>& words, int depth, int& large) {
    // visited[index] = true;

    not_visited.erase(index);

    while (!not_visited.empty()) {
      if (link[index][*not_visited.begin()] == 0) {
        not_visited.erase(not_visited.begin());
        continue;
      }

      if (link[index][*not_visited.begin()] == 1) {
        if (depth + 1 > large) {
          large = depth + 1;
        }
        dfs(*not_visited.begin(), not_visited, link, words, depth + 1, large);
        continue;
      }

      if (link[index][*not_visited.begin()] == -1) {
        if (isLinked(words[index], words[*not_visited.begin()])) {
          link[index][*not_visited.begin()] = 1;
          if (depth + 1 > large) {
            large = depth + 1;
          }
          dfs(*not_visited.begin(), not_visited, link, words, depth + 1, large);
          continue;
        } else {
          link[index][*not_visited.begin()] = 0;
          not_visited.erase(not_visited.begin());
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
      auto not_visited = set<int>();
      for (int j = 0; j < N; j++) not_visited.insert(j);
      dfs(i, not_visited, link, words, 1, large);
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
