struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int sumRootToLeaf(TreeNode *root, int base = 0) {
    if (!root) return base;
    int left =
        root->left ? sumRootToLeaf(root->left, (base << 1) + root->val) : 0;
    int right =
        root->right ? sumRootToLeaf(root->right, (base << 1) + root->val) : 0;

    if (!root->left && !root->right) {
      return (base << 1) + root->val;
    } else {
      return left + right;
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  TreeNode *root =
      new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)),
                   new TreeNode(1, new TreeNode(0), new TreeNode(1)));
  s.sumRootToLeaf(root);

  return 0;
}
