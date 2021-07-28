#include "bits/stdc++.h"

using namespace std;
long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<long long>>dp(2,vector<long long>(n,0));
    dp[0][0] = nums[0];
    for(int i=1;i<n;i++){
        dp[0][i] = max(dp[1][i-1]+nums[i],dp[0][i-1]);
        dp[1][i] = max(dp[0][i-1]-nums[i],dp[1][i-1]);
    }
    return max(dp[0][n-1],dp[1][n-1]);
}
int main() {
    vector<int>nums = {4,2,5,3};
    auto ret = maxAlternatingSum(nums);
    return 0;
}
