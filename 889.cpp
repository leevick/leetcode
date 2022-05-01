#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* myTree(int* pre, int pre_len, int* post, int post_len) {
    if (pre_len == 0) {
      return nullptr;
    }

    if (pre_len == 1) {
      return new TreeNode(pre[0]);
    }

    if (pre_len == 2) {
      auto n = new TreeNode(pre[0]);
      if (post[0] == pre[0]) {
        n->right = new TreeNode(pre[1]);
      } else {
        n->left = new TreeNode(pre[1]);
      }
      return n;
    } else {
      auto n = new TreeNode(pre[0]);
      int* pre_left = find(pre, pre + pre_len, pre[1]);
      int* pre_right = find(pre, pre + pre_len, post[post_len - 2]);
      int* post_left = find(post, post + post_len, pre[1]);
      int* post_right = find(post, post + post_len, post[post_len - 2]);

      int pre_left_len = pre_right - pre - 1;
      int post_left_len = post_left - post + 1;

      int pre_right_len = pre_len - (pre_right - pre);
      int post_right_len = post_right - post_left;

      n->left = myTree(pre + 1, pre_left_len, post, post_left_len);
      n->right = myTree(pre_right, pre_right_len, post_left + 1, post_left_len);

      return n;
    }
  };

  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    return myTree(&preorder[0], preorder.size(), &postorder[0],
                  postorder.size());
  }
};