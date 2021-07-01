#include "bits/stdc++.h"

using namespace std;
int XOR(vector<int>nums){
    if(nums.empty()) return 0;
    int x = nums[0];
    for(int i=1;i<nums.size();i++){
        x = x^nums[i];
    }
    return x;
}
void backtrace(vector<vector<int>>&ret,vector<int>nums,int sp,vector<int>tmp){
    ret.push_back(tmp);
    for(int i=sp;i<nums.size();i++){
        tmp.push_back(nums[i]);
        backtrace(ret,nums,i+1,tmp);
        tmp.pop_back();
    }
}


int subsetXORSum(vector<int>& nums) {
    vector<vector<int>>ret;
    vector<int>tmp;
    int sum = 0;
    backtrace(ret,nums,0,tmp);
    for(auto i:ret){
        sum+=XOR(i);
    }
    return sum;
}
int main() {
    vector<int>nums = {1,3};
    int ret = subsetXORSum(nums);
    return 0;
}