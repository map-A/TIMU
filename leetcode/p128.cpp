//
// Created by mm on 2021/6/15 0015.
//

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    //TODO: give a more efficient algorithm
    if(nums.empty()) return 0;
    sort(nums.begin(),nums.end());
    int left = 0,right =nums.size()-1;
    int tmp = 1,ret = 1;
    for(int i=1;i<nums.size();++i){
        if(nums[i]-1==nums[i-1]){
            tmp++;
        }
        else if(nums[i]!=nums[i-1]){
            tmp = 1;
        }
        ret = max(tmp,ret);
    }
    return ret;
}

int main(){
    vector<int>arr = {100,4,200,-3,-1,0,3,2};
    cout<<longestConsecutive(arr);
    return 0;
}
