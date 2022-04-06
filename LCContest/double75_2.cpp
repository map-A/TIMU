#include "bits/stdc++.h"

using namespace std;
int triangularSum(vector<int>& nums) {
    int t = nums.size();
    while (t>1){
        for (int i = 0; i <t-1; ++i) {
            nums[i] = (nums[i]+nums[i+1])%10;
        }
        t-=1;
    }
    return nums[0];
}
int main() {
    vector<int>nums = {1,2,3,4,5};
    int ret = triangularSum(nums);
    return 0;
}