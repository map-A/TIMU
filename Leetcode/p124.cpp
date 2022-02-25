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
int ret = INT_MIN;
int getMax(TreeNode* root){
    if(!root) return 0;
    int left = max(0, getMax(root->left));
    int right = max(0, getMax(root->right));
    int tmp = root->val+left+right;
    ret = max(ret,tmp);
    return root->val+max(right,left);
}
int maxPathSum(TreeNode* root) {
    getMax(root);
    return ret;
}
int main() {

    return 0;
}