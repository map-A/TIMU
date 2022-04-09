#include "bits/stdc++.h"

using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ret;
        if(!root) return ret;
        queue<Node*> q;
        q.push(root);
        vector<int>temp;
        while(q.size()){
            int len = q.size();
            for(int i=0;i<len;i++){
                Node* node = q.front();
                for(auto i:node->children)
                    q.push(i);
                q.pop();
                temp.push_back(node->val);
            }
            ret.push_back(temp);
            temp.clear();
        }
        return ret;
    }
};
int main() {

    return 0;
}