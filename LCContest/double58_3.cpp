#include "bits/stdc++.h"

using namespace std;


int minSpaceWastedKResizing(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        int best = INT_MIN;
        int total = 0;
        for(int j=i;j<n;j++){
            best = max(best,nums[j]);//i-j之间的最大值
            total +=nums[j];//i-j之间的数和
            g[i][j] = best*(j-i+1)-total;
        }
    }
    vector<vector<int>>dp(n,vector<int>(k+2,INT_MAX/2));
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=k+1;j++){
            for(int k=0;k<=i;k++){
                dp[i][j] = min(dp[i][j],(k==0?0:dp[k-1][j-1])+g[k][i]);
            }
        }
    }
    return dp[n-1][k+1];
}

int main() {

    return 0;
}