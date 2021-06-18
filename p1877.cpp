#include "bits/stdc++.h"

using namespace std;
int minPairSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ret = INT_MIN;
    int tmp = INT_MIN;
    for(auto i=0;i<nums.size()/2;i++){
        tmp = max(tmp,nums[i]+nums[nums.size()-i-1]);
        ret = max(ret,tmp);
    }
    return ret;
}
int main() {
    vector<int>nums = {3,5,2,5};
    int ret = minPairSum(nums);
    return 0;
}