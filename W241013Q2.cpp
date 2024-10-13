#include "leecode.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

static TreeNode *tree(vector<int> a) {
  TreeNode *root = nullptr;
  int n = a.size();

  if (n == 0) {
    root = nullptr;
    return root;
  }

  deque<TreeNode *> parentStack;
  root = new TreeNode(a[0]);
  TreeNode *curParent = root;

  for (int i = 1; i < n; ++i) {
    if (i % 2 == 1) {
      if (a[i] != -1) {
        curParent->left = new TreeNode(a[i]);
        parentStack.push_back(curParent->left);
      }
    } else {
      if (a[i] != -1) {
        curParent->right = new TreeNode(a[i]);
        parentStack.push_back(curParent->right);
      }
      curParent = parentStack.front();
      parentStack.pop_front();
    }
  }
  return root;
}

class Solution {
 public:
  void traverse(TreeNode *root, int &level, int &count, vector<int> &pq) {
    int llevel = 0, lcount = 0, rlevel = 0, rcount = 0;
    if (root == nullptr) {
      level = 0, count = 0;
      return;
    }
    traverse(root->left, llevel, lcount, pq);
    traverse(root->right, rlevel, rcount, pq);

    level = max(llevel, rlevel) + 1;
    count = lcount + rcount + 1;

    if (count == (1 << level) - 1) {
      printf("perfect node %d size = %d\n", root->val, count);
      pq.push_back(count);
    }

    return;
  }

  int kthLargestPerfectSubtree(TreeNode *root, int k) {
    vector<int> pq;
    int level = 0, count = 0;
    traverse(root, level, count, pq);
    sort(pq.begin(), pq.end());
    return pq.size() >= k ? pq[pq.size() - k] : -1;
  }
};

// Solution

int main(int argc, char const *argv[]) {
  Solution s;
  //   TreeNode *t = tree({5, 3, 6, 5, 2, 5, 7, 1, 8, -1, -1, 6, 8});
  //   auto ret = s.kthLargestPerfectSubtree(t, 2);

  TreeNode *t = tree({6, 1, 5, 9, 14});
  auto ret = s.kthLargestPerfectSubtree(t, 2);
  return 0;
}
