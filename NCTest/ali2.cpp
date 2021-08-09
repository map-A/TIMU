#include "bits/stdc++.h"

using namespace std;
//定义数
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//二叉树的插入
int InsertBST(TreeNode *&p, int k) {
    if (p == NULL) {
        p = new TreeNode(k);
        p->val = k;
        p->left = p->right = NULL;
        return 1;
    } else if (k == p->val)
        return 0;
    else if (k < p->val)
        return InsertBST(p->left, k);
    else
        return InsertBST(p->right, k);
}
//BST的构建
TreeNode *CreateBST(vector<int> &elements) {
    TreeNode *bt = NULL;
    int n = elements.size();
    int i = 0;
    while (i < n) {
        InsertBST(bt, elements[i]);
        i++;
    }
    return bt;
}

int getLeftDepth(TreeNode* root){
    if(!root) return 0;
    return getLeftDepth(root->left)+1;
}
int getRightDepth(TreeNode* root){
    if(!root) return 0;
    return getRightDepth(root->right)+1;
}


bool solve(TreeNode *root, int n) {
    if (!root) return true;
    int leftLength = getLeftDepth(root->left);
    int rightLength = getRightDepth(root->right);
    return abs(leftLength-rightLength)<=min(11,n/2)&&solve(root->left,n)&&solve(root->right,n);
}


int main() {
    int T = 0;
    scanf("%d\n", &T);
    while (T--) {
        int n = 0;
        string line;
        getline(cin,line);
        n = stoi(line);
        //scanf("%d\n", &n); //cin>>n就有问题

        vector<int> vec;
        string temp;
        //每次读取一整行
        getline(cin, line);
        //创建字符串流stringstream对象
        stringstream ss(line);
        //根据指定字符分割字符串
        while (getline(ss, temp, ' ')) {
            vec.push_back(stoi(temp));
        }
        TreeNode* root = CreateBST(vec);
        bool ret = solve(root,n);
        if(ret){
            cout<<"YES";
        }
        else{cout<<"NO";}
    }
    return 0;
}