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
class BSTIterator {
public:
    queue<int>q;
    BSTIterator(TreeNode* root) {
        help(root,q);
    }
    void help(TreeNode*node,queue<int>&s){
        if(!node) return ;
        help(node->left,q);
        s.push(node->val);
        help(node->right,q);

    }

    /** @return the next smallest number */
    int next() {
        if(hasNext()) {
            int tmp =  q.front();
            q.pop();
            return tmp;
        }
        return 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(q.empty());
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}