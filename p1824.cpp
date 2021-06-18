#include "bits/stdc++.h"

using namespace std;
int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<long long>>dp(3,vector<long long>(n,INT_MAX));
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 1;
    for(int i=1;i<n;i++){
        if(obstacles[i]==1){
            dp[1][i] = min(dp[1][i-1],1+dp[2][i]);
            dp[2][i] = min(dp[2][i-1],1+dp[1][i]);
            dp[1][i] = min(dp[1][i-1],1+dp[2][i]);
        }
        else if(obstacles[i]==2){
            dp[0][i] = min(dp[0][i-1],1+dp[2][i]);
            dp[2][i] = min(dp[2][i-1],1+dp[0][i]);
            dp[0][i] = min(dp[0][i-1],1+dp[2][i]);
        }
        else if(obstacles[i]==3){
            dp[0][i] = min(dp[0][i-1],1+dp[1][i]);
            dp[1][i] = min(dp[1][i-1],1+dp[0][i]);
            dp[0][i] = min(dp[0][i-1],1+dp[1][i]);
        }
        else{
            dp[0][i] = min({dp[0][i-1],1+dp[1][i],1+dp[2][i]});
            dp[1][i] = min({dp[1][i-1],1+dp[0][i],1+dp[2][i]});
            dp[2][i] = min({dp[2][i-1],1+dp[1][i],1+dp[0][i]});
            dp[0][i] = min({dp[0][i-1],1+dp[1][i],1+dp[2][i]});
            dp[1][i] = min({dp[1][i-1],1+dp[0][i],1+dp[2][i]});
        }
    }

    return min({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
}
int main() {
    vector<int>obstacles = {0,0,3,1,0,1,0,2,3,1,0};
    int ret = minSideJumps(obstacles);
    return 0;
}