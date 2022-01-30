#include "bits/stdc++.h"

using namespace std;
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int>tmp = {nums[0]};

    for (int i = 1; i < n; ++i) {
        if(nums[i]!=nums[i-1]){
            tmp.push_back(nums[i]);
        }
    }
    n = tmp.size();
    if(n==1){
        return 1;
    }
    if(n==2&&tmp[0]!=tmp[1]){
        return 2;
    }

    vector<int>dp(n,1);
    dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        if((tmp[i]-tmp[i-1])*(tmp[i-1]-tmp[i-2])<0){
            dp[i] = dp[i-1]+1;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    return dp[n-1];
}


int main() {
    vector<int>nums = {0,0,0};
    auto ret = wiggleMaxLength(nums);
    return 0;
}