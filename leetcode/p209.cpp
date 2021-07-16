#include "bits/stdc++.h"

using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int n =nums.size();
    if(n==0){
        return 0;
    }
    int ret = INT_MAX;
    int start = 0,end = 0;
    int sum = 0;
    while(end<n){
        sum+=nums[end];
        while(sum>=target){//向右滑动
            ret = min(ret,end-start+1);
            sum-=nums[start];
            start++;
        }
        end++;
    }
    return ret == INT_MAX?0:ret;


}
int main() {
    int target = 7;
    vector<int>nums = {2,3,1,2,4,3};
    int ret = minSubArrayLen(target,nums);
    return ret;
}