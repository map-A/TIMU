#include "bits/stdc++.h"

using namespace std;
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(1001,0)));
    dp[0][0][nums[0]] = 1;
    dp[0][1][nums[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if(dp[i-1][0][j]>0){
                dp[i][0][j+nums[i]]+=dp[i-1][0][j];
                if(j-nums[i]>0){
                    dp[i][0][j-nums[i]]+=dp[i-1][0][j];
                }
                else{
                    dp[i][1][nums[i]-j]+=dp[i-1][0][j];
                }
            }
            if(dp[i-1][1][j]>0){
                dp[i][1][j+nums[i]]+=dp[i-1][1][j];//jian
                if(nums[i]-j>0){
                    dp[i][0][nums[i]-j]+=dp[i-1][1][j];
                }
                else{
                    dp[i][1][j-nums[i]]+=dp[i-1][1][j];
                }
            }
        }
    }
    if(target<0){
        return dp[n-1][1][-target];
    }
    else if(target>0){
        return dp[n-1][0][target];
    }
    else{
        return dp[n-1][1][0]+dp[n-1][0][0];
    }
}
int main() {
    int target = 3;
    vector<int>nums = {1,1,1,1,1};
    int ret = findTargetSumWays(nums,target);
    return 0;
}