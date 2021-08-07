#include "bits/stdc++.h"

using namespace std;

int minCost(vector<vector<int>>& costs) {
    const int N = 101;
    int dp[N][3];
    memset(dp,0, sizeof(dp));
    for(int i=1;i<=costs.size();i++){
        dp[i][0] = min({dp[i-1][1]+costs[i-1][1],dp[i-1][2]+costs[i-1][2]});
        dp[i][1] = min({dp[i-1][0]+costs[i-1][0],dp[i-1][2]+costs[i-1][2]});
        dp[i][2] = min({dp[i-1][0]+costs[i-1][0],dp[i-1][1]+costs[i-1][1]});
    }
    return min({dp[costs.size()][0],dp[costs.size()][1],dp[costs.size()][2]});
}


int main() {
    vector<vector<int>>costs = {{7,6,2}};
    int ret = minCost(costs);

    return 0;
}