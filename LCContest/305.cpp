#include "bits/stdc++.h"

using namespace std;

int arithmeticTriplets(vector<int> &nums, int diff) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if ((nums[j] - nums[i] == diff) && (nums[k] - nums[j] == diff)) {
                    ret++;
                }
            }
        }
    }
    return ret;
}


int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &r) {
    vector<int> rest(n), vis(n);
    for (int x: r) rest[x] = 1;
    vector<vector<int>> G(n);
    for (auto v: edges) {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    int ans = 0;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        if (rest[u]) continue;
        ans += 1;
        for (int v: G[u])
            if (not vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
    }
    return ans;

}


bool validPartition(vector<int>& nums) {
    int len = nums.size();
    vector<bool>dp(len,false);
    dp[1] = nums[0]==nums[1];
    if(len==2){
        return dp[1];
    }
    dp[2] = (dp[1]&&nums[1]==nums[2])||(nums[1] == nums[0] + 1 && nums[2] == nums[1] + 1);
    for (int i = 3; i < len; i++) {
        bool b1 = dp[i - 2] && nums[i - 1] == nums[i];
        bool b2 = dp[i - 3] && nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i];
        bool b3 = dp[i - 3] && nums[i - 1] == nums[i - 2] + 1 && nums[i] == nums[i - 1] + 1 ;
        dp[i] = b1 || b2 || b3;
    }
    return dp[len-1];
}



int longestIdealString(string s, int k) {
    vector<int> dp(26);
    for (char c : s) {
        int x = c - 'a', mx = 0;
        for (int y = max(x - k, 0); y <= min(x + k, 25); y += 1)
            mx = max(mx, dp[y]);
        dp[x] = mx + 1;
    }
    return *max_element(dp.begin(), dp.end());
}
int main() {

    return 0;
}