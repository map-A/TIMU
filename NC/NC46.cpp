#include "bits/stdc++.h"

using namespace std;

void backtrace(vector<int>&nums,vector<int>tmp,int index,vector<vector<int>>&ret,int sum,int target){
    if(sum==target){
        ret.push_back(tmp);
    }
    if(target<sum){
        return ;
    }
    for(int i=index;i<nums.size();i++){
        tmp.push_back(nums[i]);
        backtrace(nums,tmp,i+1,ret,sum+nums[i],target);
        tmp.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {

    vector<int>tmp;
    vector<vector<int>>ret;
    vector<vector<int>>final_ret;
    set<vector<int>>s;
    sort(num.begin(),num.end());
    backtrace(num,tmp,0,ret,0,target);
    for(auto i:ret){
        sort(i.begin(),i.end());
        s.insert(i);
    }
    for(auto i:s){
        final_ret.push_back(i);
    }
    return ret;
}




int main() {

    return 0;
}