#include "bits/stdc++.h"

using namespace std;

void moveZeroes(vector<int>& nums) {
    int firstZero = -1;
    int firstNonZero = -1;
    for(int i = 0; i < nums.size(); i++){
        if(firstZero == -1 && nums[i] == 0){
            firstZero = i;
            for(int j = firstZero; j < nums.size(); j++){
                if(nums[j] != 0){
                    firstNonZero = j;
                    break;
                }
            }
            if(firstNonZero != -1 && firstZero != -1){
                int temp = nums[firstZero];
                nums[firstZero] = nums[firstNonZero];
                nums[firstNonZero] = temp;
                firstZero = -1;
                firstNonZero = -1;
            }
        }
    }
}

int main() {
    vector<int> nums = {0,1,0,0,3,12};
    moveZeroes(nums);
    return 0;
}