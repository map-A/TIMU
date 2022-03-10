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

TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> mp;
    unordered_map<int, int> degreeIn;
    for (auto &d: descriptions) {
        int p = d[0], c = d[1], left = d[2];
        if (!mp.count(p)) { /* 创建父节点 */
            mp[p] = new TreeNode(p);
        }
        if (!mp.count(c)) { /* 创建孩子节点 */
            mp[c] = new TreeNode(c);
        }
        if (left) { /* 父节点指向孩子节点 */
            mp[p]->left = mp[c];
        } else {
            mp[p]->right = mp[c];
        }

        degreeIn[c]++; /* 计算入度值 */
    }
    for (auto &[val, node]: mp) { /* 入度为0为父节点 */
        if (!degreeIn.count(val)) {
            return node;
        }
    }
    return nullptr;
}

int main() {

    return 0;
}