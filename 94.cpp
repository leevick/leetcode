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

            cout << "top = " << top->val << endl;

            if (top->left != nullptr) {
                stack.push(top->left);
                continue;
            }

            res.push_back(top->val);

            if (top->right != nullptr) {
                stack.push(top->right);
                continue;
            }

            stack.pop();
            if (!stack.empty()) {
                if (stack.top()->left == top) {
                    stack.top()->left = nullptr;
                }
                if (stack.top()->right == top) {
                    stack.top()->right = nullptr;
                }
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    auto root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    Solution s;
    auto ret = s.inorderTraversal(root);

    for (auto r : ret) {
        cout << r << endl;
    }

    return 0;
}
