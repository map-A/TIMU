#include "bits/stdc++.h"

using namespace std;
int findMaximumXOR(vector<int>& nums) {
    if(nums.size()==1)return 0;
    int ret = INT_MIN;
    int tmp = INT_MIN;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();++j){
            tmp = max(tmp,nums[i]^nums[j]);
            ret = max(ret,tmp);
        }
    }
    return ret;
}
int main() {
    vector<int>nums ={3,10,5,25,2,8};
    int ret = findMaximumXOR(nums);
    return 0;
}