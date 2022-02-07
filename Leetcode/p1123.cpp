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

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        vector<TreeNode*>node;
        q.push(root);
        while(!q.empty()){
            int len =q.size();
            node.clear();
            for(int i=0;i<len;i++){
                TreeNode* tmp = q.front();
                node.push_back(tmp);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        while(true){
            if(node.size()==1) return node[0];
            else{
                TreeNode* p = node[0];
                TreeNode* q = node[1];
                node.erase(node.begin());
                node.erase(node.begin());
                TreeNode* tmp = lowestCommonAncestor(root,p,q);
                node.push_back(tmp);
            }
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==q||root==p) return root;
        TreeNode*left =  lowestCommonAncestor(root->left,p,q);
        TreeNode*right =  lowestCommonAncestor(root->right,p,q);
        TreeNode* ret;
        ((ret=root)&&(left && right))||(ret = left)||(ret = right);
        return ret;
    }
};

int main() {

    return 0;
}