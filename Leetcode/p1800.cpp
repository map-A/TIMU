#include "bits/stdc++.h"

using namespace std;
int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n);
    dp[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]){
            dp[i] = nums[i]+dp[i-1];
        }
        else{
            dp[i] = nums[i];
        }
    }
    return *max_element(dp.begin(),dp.end());
}
int main() {

    return 0;
}