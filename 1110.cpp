#include <stack>
#include <vector>
#include <map>
#include <set>

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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        map<int, TreeNode *> segs;
        segs[root->val] = root;
        vector<TreeNode *> ret;
        set<int> del;
        for (auto d : to_delete) {
            del.insert(d);
        }

        auto q = stack<TreeNode *>();
        q.push(root);

        while (!q.empty()) {
            auto cur = q.top();
            q.pop();

            if (del.find(cur->val) != del.end()) {
                segs.erase(cur->val);
                if (cur->right) {
                    segs[cur->right->val] = cur->right;
                }

                if (cur->left) {
                    segs[cur->left->val] = cur->left;
                }
            }

            if (cur->right) {
                q.push(cur->right);
                if (del.find(cur->right->val) != del.end()) {
                    cur->right = nullptr;
                }
            }

            if (cur->left) {
                q.push(cur->left);
                if (del.find(cur->left->val) != del.end()) {
                    cur->left = nullptr;
                }
            }
        }

        for (auto i : segs) {
            ret.push_back(i.second);
        }
        return ret;
    }
};