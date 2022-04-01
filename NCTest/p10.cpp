#include "bits/stdc++.h"

using namespace std;


struct TreeNode {
        char val;
        TreeNode *left;
         TreeNode *right;
         TreeNode(char x) : val(x), left(NULL), right(NULL) {}
     };

TreeNode* build(vector<char>&preorder,vector<char>inorder,int root,int start,int end){
    if(start>end) return NULL;
    TreeNode* tree = new TreeNode(preorder[root]);
    int i = start;
    while(i<end&&preorder[root]!=inorder[i]) ++i;
    tree->left = build(preorder,inorder,root+1,start,i-1);
    tree->right =build(preorder,inorder,root+i-start+1,i+1,end);
    return tree;
}
TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
    return build(preorder,inorder,0,0,preorder.size()-1);
}


void helper(TreeNode*node,vector<int>&ret){
    if(!node) return ;
    helper(node->left,ret);
    helper(node->right,ret);
    ret.push_back(node->val);
}

vector<char> postorderTraversal(TreeNode* root) {
    vector<char>ret;
    helper(root,ret);
    return ret;
}


int main() {

    return 0;
}