#include "bits/stdc++.h"

using namespace std;
int minOperations(vector<int>& nums) {
    int tmp = nums[0];
    int ret = 0;
    int i;
    for(i=1;i<nums.size();++i){
        if(nums[i]>tmp){
            tmp = nums[i];
        }
        else{
            ret+=(tmp-nums[i]+1);
            tmp = tmp+1;
        }
    }
    return ret;
}

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int>ret;
    for(auto i:queries){
        int count = 0;
        for(auto j : points){
            if(pow(j[0]-i[0],2)+pow(j[1]-i[1],2)<=pow(i[2],2)){
                count++;
            }
        }
        ret.push_back(count);
    }
    return ret;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int total = nums[0];
    vector<int>ret;
    int tmp;
    for(int i=1;i<nums.size();++i){
        tmp =total%(int)pow(2,maximumBit);
        ret.push_back(tmp^(int)(pow(2,maximumBit)-1));
        total = total^nums[i];
    }
    tmp =total%(int)pow(2,maximumBit);
    ret.push_back(tmp^(int)(pow(2,maximumBit)-1));
    reverse(ret.begin(),ret.end());
    return ret;
}

int main() {
    vector<int>nums = {4881,2593,6819,9256,4135};
    int ret = minOperations(nums);
    return 0;
}