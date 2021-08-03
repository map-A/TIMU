#include "bits/stdc++.h"

using namespace std;

const int N=100007;
int countSpecialSubsequences(vector<int>& nums) {
    int mod = 1e9+7;
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        if(nums[i-1]==0){
            dp[i][0] = ((2*dp[i-1][0])%mod+1)%mod;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];
        }
        else if(nums[i-1]==1){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = ((2*dp[i-1][1])%mod +dp[i-1][0])%mod;
            dp[i][2] = dp[i-1][2];
        }
        else if(nums[i-1]==2){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = ((2*dp[i-1][2])%mod+dp[i-1][1])%mod;
        }
    }
    return dp[n][2];
}

int main() {
    vector<int> nums= {0,1,2,2};
    int ret = countSpecialSubsequences(nums);
    cout<<ret;
    return 0;
}