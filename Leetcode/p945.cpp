#include "bits/stdc++.h"

using namespace std;

int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int vis[1000003] = {0};
    for (int i = 0; i < nums.size();i++) {
        vis[nums[i]]=1;
    }
    int index = 1;
    int ret = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i]==nums[i-1]){
            //发生重复，在vis里面找到一个最
            index= index>nums[i]?index:nums[i];
            for (; index < 1000003; ++index) {
                if(vis[index]==0){
                    vis[index]=1;
                    ret+=index-nums[i];
                    break;
                }
            }
        }
    }
    return ret;
}
int main() {
    vector<int>nums = {3,2,1,2,1,7};
    auto ret = minIncrementForUnique(nums);
    return 0;
}