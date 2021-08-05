#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void sumBST(TreeNode* root,int& sum){
    if(!root) return;
    sumBST(root->right,sum);
    root->val+=sum;
    sum = root->val;
    sumBST(root->left,sum);
}

TreeNode* convertBST(TreeNode* root) {
    int sum=0;
    sumBST(root,sum);
    return root;
}

int main() {
    return 0;
}
