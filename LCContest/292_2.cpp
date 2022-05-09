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
    int ans = 0;
public:
    pair<int, int> dfs(TreeNode* p) {
        int x = 1, y = p->val;
        if (p->left) {
            auto z = dfs(p->left);
            x += z.first; y += z.second;
        }
        if (p->right) {
            auto z = dfs(p->right);
            x += z.first; y += z.second;
        }
        if (y / x == p->val)
            ++ans;
        return {x, y};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
int main() {

    return 0;
}