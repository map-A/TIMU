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


int getDepth(TreeNode* root){
    if(!root) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return max(l,r)+1;
}
void help(vector<vector<string>>&ret,TreeNode*root,int l,int r,int level){
    if(!root) return;
    string s = to_string(root->val);
    int pos = (l+r)/2;
    ret[level][pos] = s;
    help(ret,root->left,l,pos,level+1);
    help(ret,root->right,pos,r,level+1);

}
vector<vector<string>> printTree(TreeNode *root) {
    int depth = getDepth(root);
    int width = (int)pow(2,depth)-1;
    vector<vector<string>>ret(depth,vector<string>(width,""));
    help(ret,root,0,width,0);
}

int main() {

    return 0;
}