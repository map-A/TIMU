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
int main() {
    vector<int>nums = {1,2,3,4,10,5,5};
    int ret = canBeIncreasing(nums);
    return 0;
}