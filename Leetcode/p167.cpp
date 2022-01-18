#include "bits/stdc++.h"

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size()-1;
    int current = 0;
    while(l < r){
        current = numbers[l] + numbers[r];
        if(current == target){
            return {l+1, r+1};
        }
        else if(current < target){
            l += 1;
        }
        else if(current > target){
            r -= 1;
        }
    }
    return {};
}

int main() {
    auto start = std::chrono::system_clock::now().time_since_epoch();
    auto end  =  std::chrono::system_clock::now();
    vector<int>nums = {2,7,11,15};
    int target = 9;
    auto ret = twoSum(nums,target);
    return 0;
}