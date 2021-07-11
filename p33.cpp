#include "bits/stdc++.h"

using namespace std;

int search1(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i]) {
            return i;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target) {
    int left = 0,right = nums.size()-1;
    int mid;
    while(left<=right){
        mid = left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>=nums[left]){
            //如果从left到mid有序
            if(target>nums[mid]||(target<nums[mid]&&target<nums[left])){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        else if(nums[mid]<nums[right]){
            if(target<nums[mid]||(target>nums[mid]&&target>nums[right])){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
    }
    return -1;
}
int main() {
    vector<int>nums = {6,8,10,0,2,4};
    int target = 0;
    int ret = search(nums,target);
    return 0;
}