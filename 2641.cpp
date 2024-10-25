#include "leetcode.hpp"

class Solution {
 public:
  void levelSum(TreeNode *root, int level, vector<int> &sums) {
    if (root == nullptr) return;

    if (level >= sums.size()) {
      sums.push_back(root->val);
    } else {
      sums[level] += root->val;
    }

    levelSum(root->left, level + 1, sums);
    levelSum(root->right, level + 1, sums);
  }

  void cousinsSum(TreeNode *node, int level, vector<int> &sums) {
    if (node->left == nullptr && node->right == nullptr) return;

    int left = node->left ? node->left->val : 0;
    int right = node->right ? node->right->val : 0;

    if (node->left) {
      node->left->val = sums[level + 1] - right - left;
      cousinsSum(node->left, level + 1, sums);
    }

    if (node->right) {
      node->right->val = sums[level + 1] - left - right;
      cousinsSum(node->right, level + 1, sums);
    }
  }

  TreeNode *replaceValueInTree(TreeNode *root) {
    vector<int> sums;
    levelSum(root, 0, sums);
    root->val = 0;
    cousinsSum(root, 0, sums);
    return root;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> t1 = {5, 4, 9, 1, 10, -1, 7}, t2 = {3, 1, 2};
  s.replaceValueInTree(TreeNode::construct(t1));
  return 0;
}
