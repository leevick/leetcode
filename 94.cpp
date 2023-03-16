#include <stack>
#include <vector>
#include <iostream>

using namespace std;

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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stack = {};
        vector<int> res = {};
        stack.push(root);

        while (!stack.empty()) {
            auto top = stack.top();

            if (top == nullptr) {
                stack.pop();
                continue;
            }

            auto left = top->left;
            auto right = top->right;

            if (left != nullptr) {
                if (left->val > -101) {
                    stack.push(left);
                    continue;
                }
            }

            if (top->val > -101) {
                res.push_back(top->val);
                top->val = -101;
            }

            if (right != nullptr) {
                if (right->val > -101) {
                    stack.push(right);
                    continue;
                }
            }

            stack.pop();
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), nullptr);
    Solution s;
    auto ret = s.inorderTraversal(root);

    for (auto r : ret) {
        cout << r << endl;
    }

    return 0;
}
