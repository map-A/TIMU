#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
        TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
string tree2str(TreeNode* t) {
    string ret = "";
    if(!t) return ret;
    if(!t->left&&!t->right){
        ret.append(to_string(t->val));//在这里仅仅只添加value
        return ret;
    }
    ret.append(to_string(t->val));//访问根节点
    ret+=("("+tree2str(t->left)+")");//访问左子树，同时给两边加上（）
    if(t->right)//访问右子树，加上括号
        ret+=("("+tree2str(t->right)+")");
    return ret;
}
int main() {

    return 0;
}