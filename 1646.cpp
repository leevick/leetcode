#include <string>
#include <iostream>
#include <vector>

using namespace std;

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node
{
public:
    virtual ~Node() {
        delete left;
        delete right;
    };
    virtual int evaluate() const = 0;

protected:
    // define your fields here
    Node *left;
    Node *right;
    string value;
};

class MyNode : public Node
{
public:
    MyNode(string v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    virtual ~MyNode() {}
    virtual void setLeft(Node *left) {
        this->left = left;
    };

    virtual void setRight(Node *right) {
        this->right = right;
    }
    virtual int evaluate() const {
        if (value[0] == '+') {
            return left->evaluate() + right->evaluate();
        } else if (value[0] == '-') {
            return left->evaluate() - right->evaluate();
        } else if (value[0] == '*') {
            return left->evaluate() * right->evaluate();
        } else if (value[0] == '/') {
            return left->evaluate() / right->evaluate();
        } else {
            return atoi(value.c_str());
        }
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder
{
public:
    Node *buildTree(vector<string> &postfix) {
        const int N = postfix.size();
        vector<MyNode *> v(N, nullptr);

        for (auto i = 0; i < N; i++) {
            v[i] = new MyNode(postfix[i]);
            if (postfix[i][0] == '+' || postfix[i][0] == '-' || postfix[i][0] == '*' || postfix[i][0] == '/') {

                int j = i - 1;
                while (v[j] == nullptr)
                    j--;
                v[i]->setRight(v[j]);
                v[j] = nullptr;
                j--;
                while (v[j] == nullptr)
                    j--;
                v[i]->setLeft(v[j]);
                v[j] = nullptr;
            }
        }

        return v[N - 1];
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */