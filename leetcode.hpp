#pragma once

#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
  static TreeNode *construct(vector<int> a) {
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
};