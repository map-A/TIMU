#include "bits/stdc++.h"

using namespace std;
vector<string> cellsInRange(string s) {
    vector<string> v;
    for(char i=s[0];i<=s[3];i++)
        for(char j=s[1];j<=s[4];j++){
            string t;
            t += i;
            t += j;
            v.emplace_back(t);
        }
    return v;
}

// 按照数字间的间隔消耗k
long long minimalKSum(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    long long ret = 0;
    int j = 1;
    for (int i = 0; i < nums.size()&&k; ++i) {
        if(nums[i]-j>0){
            int d = min(k,nums[i]-j);
            ret+=(long long)(j+j+d-1)*d/2;
            k-=d;
        }
        j = nums[i]+1;
    }
    if(k){
        ret +=(long long )(j+j+k-1)*k/2;
    }
    return ret;
}

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