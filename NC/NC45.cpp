#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void preOrder(TreeNode *root, vector<int> &ret) {
    if (!root) {
        return;
    }
    ret.push_back(root->val);
    preOrder(root->left, ret);
    preOrder(root->right, ret);
}

void inOrder(TreeNode *root, vector<int> &ret) {
    if (!root) {
        return;
    }
    inOrder(root->left, ret);
    ret.push_back(root->val);
    inOrder(root->right, ret);
}

void posOrder(TreeNode *root, vector<int> &ret) {
    if (!root) {
        return;
    }
    posOrder(root->left, ret);
    posOrder(root->right, ret);
    ret.push_back(root->val);
}

vector<vector<int> > threeOrders(TreeNode *root) {
    vector<int> pre;
    preOrder(root, pre);
    vector<int> in;
    inOrder(root, in);
    vector<int> pos;
    posOrder(root, pos);
    return {pre, in, pos};
}


vector<int> PreOrderNonRecur(TreeNode *root) {
    TreeNode *T = root;
    stack<TreeNode *> S;
    vector<int> ret;
    while (T || !S.empty()) {
        while (T) {
            ret.push_back(T->val);
            S.push(T);
            T = T->left;
        }
        if (!S.empty()) {
            T = S.top();
            S.pop();
            T = T->right;
        }
    }
    return ret;
}

vector<int> inOrderNonRecur(TreeNode *root) {
    TreeNode *T = root;
    stack<TreeNode *> S;
    vector<int> ret;
    while (T || !S.empty()) {
        while (T) {
            S.push(T);
            T = T->left;
        }
        if (!S.empty()) {
            T = S.top();
            S.pop();
            ret.push_back(T->val);
            T = T->right;
        }
    }
    return ret;
}

vector<int> posOrderNonRecur(TreeNode *root) {
    TreeNode *T = root;
    stack<TreeNode *> S1;
    stack<TreeNode *> S2;
    while (T || !S1.empty()) {
        while (T) {
            S2.push(T);
            S1.push(T);
            T = T->right;
        }
        if (!S1.empty()) {
            T = S1.top();
            S1.pop();
            T = T->left;
        }
    }
    vector<int> ret;
    while (!S2.empty()) {
        ret.push_back(S2.top()->val);
        S2.pop();
    }
    return ret;
}

vector<vector<int> > threeOrders2(TreeNode *root) {
    vector<int> pre = PreOrderNonRecur(root);
    vector<int> in = inOrderNonRecur(root);
    vector<int> pos = posOrderNonRecur(root);
    return {pre, in, pos};
}


int main() {

    return 0;
}