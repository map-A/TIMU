#include "bits/stdc++.h"

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    int mid;
    while(left < right){
        mid = left + (right-left) / 2;
        if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] >= target){
            right = mid;
        }
    }
    int ret;
    ret = nums[left] == target ? left : -1;
    return ret;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    int ret = search(nums, target);
    return 0;
}