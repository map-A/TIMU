#include "bits/stdc++.h"

using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
*/
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        helper(root,v);
        for(vector<int>::iterator i=v.begin();i!=v.end();i++){
            if(find(i+1,v.end(),k-*i)!=v.end())
                return true;
        }
        return false;
    }
    void helper(TreeNode* root,vector<int>&v){
        if(!root) return;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
};


int main() {

    return 0;
}