#include "bits/stdc++.h"

using namespace std;

bool isThree(int n) {
    if(n<3) return  false;
    int sq = (int)sqrt(n);
    if(n==sq*sq){
        for(int i=2;i<sq;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    return false;
}


long long numberOfWeeks(vector<int> &milestones) {
    // 耗时最长工作所需周数
    long long longest = *max_element(milestones.begin(), milestones.end());
    // 其余工作共计所需周数
    long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - longest;
    if (longest > rest + 1) {
        // 此时无法完成所耗时最长的工作
        return rest * 2 + 1;
    } else {
        // 此时可以完成所有工作
        return longest + rest;
    }
}

long long minimumPerimeter(long long neededApples) {
    long long sum = 0;
    long long i = 0;
    long long total = 0;
    while(total<neededApples){
        i++;
        sum += 24*i-12;
        total+=sum;
    }
    return (i)*8;
}


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
    string s = "leetcode";

    return 0;
}