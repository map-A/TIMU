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


TreeNode* helper(TreeNode* node){
    if(!node) return NULL;
    node->left = helper(node->left);
    node->right = helper(node->right);
    if(node->val==0&&!node->left&&!node->right)
        return NULL;
    return node;
}
TreeNode* pruneTree(TreeNode* root) {
    return helper(root);

}
