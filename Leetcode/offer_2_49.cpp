#include "bits/stdc++.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int help(TreeNode *root, int sum) {
    if (root == nullptr) {
        return 0;
    }
    int val = sum * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr) {
        return val;
    }
    return help(root->left, val) + help(root->right, val);
}

int sumNumbers(TreeNode *root) {
    int ret = help(root, 0);
    return ret;
}

int main() {

    return 0;
}