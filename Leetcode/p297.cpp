#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };



class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ret;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp){
                    ret+=to_string(tmp->val);
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                else{
                    ret+="null";
                }
                ret+=",";
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        vector<string>vec;
        string temp;
        stringstream ss(data);
        while (getline(ss, temp, ',')) {
            vec.push_back(temp);
        }
        auto* root = new TreeNode(stoi(vec[0]));
        queue<TreeNode*>q;
        q.push(root);
        int index = 1;
        while (index<vec.size()){
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(vec[index]!="null"){
                    TreeNode *left = new TreeNode(stoi(vec[index++]));
                    tmp->left = left;
                    q.push(left);
                }
                else{
                    index++;
                    tmp->left = NULL;
                }
                if(vec[index]!="null"){
                    TreeNode *right = new TreeNode(stoi(vec[index++]));
                    tmp->right = right;
                    q.push(right);
                }
                else{
                    index++;
                    tmp->right = NULL;
                }
            }
        }
        return root;
    }
};
int main() {

    return 0;
}