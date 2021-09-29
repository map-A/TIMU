#include "bits/stdc++.h"

using namespace std;
int minOperations(vector<int>& nums) {
    int tmp = nums[0];
    int ret = 0;
    int i;
    for(i=1;i<nums.size();++i){
        if(nums[i]>tmp){
            tmp = nums[i];
        }
        else{
            ret+=(tmp-nums[i]+1);
            tmp = tmp+1;
        }
    }
    return ret;
}
int main() {
    vector<int>nums = {4881,2593,6819,9256,4135};
    int ret = minOperations(nums);
    return 0;
}