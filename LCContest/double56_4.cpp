#include "bits/stdc++.h"

using namespace std;
int minCost(int maxTime,vector<vector<int>>&edges,vector<int>passingFees){
    int n = passingFees.size();
    vector<vector<int>>dp(maxTime+1,vector<int>(n,INT_MAX/2));
    dp[0][0] = passingFees[0];
    for(int i=1;i<=maxTime;i++){
        for(auto &edge:edges){
            int s = edge[0],t = edge[1],cost = edge[2];
            if(cost<=i){
                dp[i][s] = min(dp[i][s],dp[i-cost][t]+passingFees[s]);
                dp[i][t] = min(dp[i][t],dp[i-cost][s]+passingFees[t]);
            }
        }
    }
    int ret = INT_MAX/2;
    for(int i=1;i<=maxTime;i++){
        ret = min(ret,dp[i][n-1]);
    }
    return ret==INT_MAX/2?-1:ret;
}
int main() {
    return 0;
}