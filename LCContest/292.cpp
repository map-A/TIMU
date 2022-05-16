#include "bits/stdc++.h"

using namespace std;
string largestGoodInteger(string num) {
    vector<string>arr = { "999", "888", "777", "666", "555", "444", "333", "222", "111", "000" };
    for (auto & s : arr) {
        if (num.find(s)!=num.npos) return s;
    }
    return "";
}


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


int f[100010];
const int mod = 1e9+7;
int countTexts(string s) {
    int n = s.size();
    f[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=4; j++) {
            if(i-j<0)
                break;
            if(s[i-j]!=s[i-1])
                break;
            if(j==4 && s[i-1]!='7' && s[i-1]!='9')
                break;
            f[i] += f[i-j];
            f[i] %= mod;
        }
    }
    return f[n];
}
int main() {

    return 0;
}