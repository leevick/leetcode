

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root, TreeNode *tail = nullptr) {
        if (!root)
            return tail;
        root->right = increasingBST(root->right, tail);
        auto left = root->left;
        root->left = nullptr;
        return increasingBST(left, root);
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    TreeNode *root = new TreeNode(5, new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(8, new TreeNode(7), new TreeNode(9))));
    TreeNode *ret = s.increasingBST(root);
    return 0;
}
