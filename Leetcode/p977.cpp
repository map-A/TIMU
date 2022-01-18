#include "bits/stdc++.h"

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        nums[i] = nums[i]*nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main() {
    vector<int> nums = {-7,-3,2,3,11};
    vector<int> res = sortedSquares(nums);
    return 0;
}