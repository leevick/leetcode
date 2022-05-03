#include <map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  void traverse(Node* root, int depth, map<int, Node*>& link) {
    if (root == nullptr) return;

    auto it = link.find(depth);
    if (it == link.end()) {
      link.insert(make_pair(depth, root));
    } else {
      it->second->next = root;
      it->second = root;
    }

    traverse(root->left, depth + 1, link);
    traverse(root->right, depth + 1, link);
  }
  Node* connect(Node* root) {
    map<int, Node*> links;
    traverse(root, 0, links);
    return root;
  }
};
