#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct lim {
  mutable long long l;
  mutable long long r;
  mutable unsigned long long span;
  lim() {
    l = INT64_MAX;
    r = INT64_MIN;
    span = INT64_MIN;
  }
};

class Solution {
 public:
  void myTree(TreeNode *root, int d, unsigned long long pos,
              unordered_map<int, lim> &l) {
    if (root == nullptr) {
      return;
    }

    // Update max span
    auto it = l.find(d);

    if (it == l.end()) {
      l.insert(make_pair(d, lim()));
      it = l.find(d);
    }

    if (pos > it->second.r) {
      it->second.r = pos;
      if (it->second.l != INT64_MAX) {
        it->second.span = it->second.r - it->second.l;
      }
    }

    // Update max span
    if (pos < it->second.l) {
      it->second.l = pos;
      if (it->second.r != INT64_MIN) {
        it->second.span = it->second.r - it->second.l;
      }
    }

    // Traverse left
    myTree(root->left, d + 1, 2 * pos, l);

    // Traverse right
    myTree(root->right, d + 1, 2 * pos + 1, l);
  }

  int widthOfBinaryTree(TreeNode *root) {
    unordered_map<int, lim> limits;
    int mxd = 0;
    myTree(root, 0, 0, limits);
    int mx = -1;

    for (auto i : limits) {
      if (i.second.span > mx) {
        mx = i.second.span;
      }
    }
    return mx + 1;
  }
};