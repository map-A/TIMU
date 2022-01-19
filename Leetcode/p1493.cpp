#include "bits/stdc++.h"

using namespace std;
int longestSubarray(vector<int>& nums) {
    int sum  = accumulate(nums.begin(),nums.end(),0);
    if(sum==nums.size()) return sum-1;
    if(sum==nums.size()-1) return sum;
    if(sum==0) return 0;
    int n = nums.size();
    vector<int>dp(n+2);
    for (int i = 0; i < n; ++i) {
        if(nums[i]==0){
            dp[i+1]=0;
        }
        else{
            dp[i+1] = dp[i]+1;
        }
    }
    int ret = 0;
    int l = 1,r = 1;
    while (r<n+2){
        if(dp[r]==0){
            ret =max(ret,dp[l-1]+dp[r-1]);
            l = r;
        }
        r++;
    }
    return ret;
}
int main() {
    vector<int>nums = {0,1,1,1,0,1,1,0,1};
    int ret = longestSubarray(nums);
    return 0;
}