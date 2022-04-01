#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int solve(TreeNode* root) {
        vector<int> ret=help(root);
        return  max(ret[0],ret[1]);
    }
    vector<int> help(TreeNode* root){
        if(root==nullptr)
            return vector<int>(2,0);
        vector<int> left=help(root->left);
        vector<int> right=help(root->right);

        vector<int> ret(2,0);
        ret[0]=max(left[1],left[0])+ max(right[0],right[1]);       //当不rob根节点时，最大值为左右两个节点随便搞的最大值。也可以不rob子节点。只要最优解！
        ret[1]=root->val+left[0]+right[0];

        return ret;
    }
};
int main() {

    return 0;
}