#include "bits/stdc++.h"

using namespace std;
bool canBeIncreasing(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i=1;i<n-1;i++){
        if(nums[i-1]<nums[i]&&nums[i]<nums[i+1]){
            continue;
        }
        else if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]&&nums[i+1]>nums[i-1]){
            nums[i] = nums[i-1];
            count++;
        }
        else if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]&&nums[i+1]<=nums[i-1]){
            count++;
            nums[i+1] = nums[i];
            i+=1;

        }
        else if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]&&nums[i+1]>nums[i-1]){
            nums[i] = nums[i-1];
            count++;
        }
        else if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]&&nums[i+1]<=nums[i-1]){
            count++;
        }
        else {
            return false;
        }
    }
    if(nums[n-1]<nums[n-2]) count++;
    if(count>=2)  return false;
    return true;
}

string removeOccurrences(string s, string part) {
    size_t pos = s.find(part);
    string tmp = s;
    while(pos!=std::string::npos){
        tmp =tmp.replace(pos,part.size(),"");
        pos = tmp.find(part);
    }
    return tmp;
}

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
    vector<int>nums = {1,2,3,4,10,5,5};
    int ret = canBeIncreasing(nums);
    return 0;
}