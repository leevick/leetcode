#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool dfs(int i, int j, int index, vector<vector<char>>& board, string& word,
           set<pair<int, int>>& visited) {
    const int rows = board.size();
    const int cols = board[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols) {
      return false;
    }

    if (visited.find(make_pair(i, j)) != visited.end()) {
      return false;
    }

    if (index == word.length()) {
      return true;
    }

    if (board[i][j] != word[index]) {
      return false;
    } else if (index + 1 == word.length()) {
      return true;
    }

    visited.insert(make_pair(i, j));

    if (dfs(i - 1, j, index + 1, board, word, visited)) {
      return true;
    } else {
      visited.clear();
      visited.insert(make_pair(i, j));
    }
    if (dfs(i + 1, j, index + 1, board, word, visited)) {
      return true;
    } else {
      visited.clear();
      visited.insert(make_pair(i, j));
    }
    if (dfs(i, j - 1, index + 1, board, word, visited)) {
      return true;
    } else {
      visited.clear();
      visited.insert(make_pair(i, j));
    }
    if (dfs(i, j + 1, index + 1, board, word, visited)) {
      return true;
    } else {
      visited.clear();
      visited.insert(make_pair(i, j));
    }
    visited.clear();
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    const int rows = board.size();
    const int cols = board[0].size();
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++) {
        set<pair<int, int>> visited;
        if (dfs(i, j, 0, board, word, visited)) {
          return true;
        }
      }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<char>> grid = {{'a', 'b'}, {'c', 'd'}};
  s.exist(grid, "cdba");
  return 0;
}
