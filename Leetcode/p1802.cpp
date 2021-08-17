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


// 从先序遍历还原二叉树
TreeNode *recoverFromPreorder(string traversal) {
    vector<pair<int, int>> vec;
    vec.push_back({0, 0}); //level-val
    for (int i = 0; i < traversal.size(); i++) {
        int level = 0;
        int j;
        for(j=i;j<traversal.size();j++) {
            if (traversal[j] == '-') {
                level++;
            } else if (traversal[j] != '-' && level != 0) {
                vec.push_back({level, 0});
                i = j;
                break;
            }
        }
    }
    string tmp;
    stringstream ss(traversal);
    int i = 0;
    while(getline(ss, tmp, '-')){
        if(!tmp.empty())
        vec[i++].second= stoi(tmp);
    }

    stack<pair<TreeNode*,int>>s;
    TreeNode* root = new TreeNode(vec[0].second);
    s.push({root,vec[0].first});
    for(int i=1;i<vec.size();i++){
        while(!s.empty()&&vec[i].first!=s.top().second+1){
            s.pop();
        }
        if(!s.empty()&&vec[i].first==s.top().second+1){
            if(s.top().first->left==NULL){
                TreeNode* left = new TreeNode(vec[i].second);
                s.top().first->left = left;
                s.push({left,vec[i].first});
            }
            else if(s.top().first->right==NULL){
                TreeNode* right = new TreeNode(vec[i].second);
                s.top().first->right = right;
                s.push({right,vec[i].first});
            }
        }

    }

    return root;

}
int main() {
    string traversal = "1-2--3--4-5--6--7";
    recoverFromPreorder(traversal);
    return 0;
}