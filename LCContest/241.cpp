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


int minSwaps(string s) {
    int n = s.size();
    int n0 = count(s.begin(),s.end(),'0');
    int n1 = n-n0;
    int ret = INT_MAX;
    if(n1==(n+1)/2&&n0==n/2){
        int diff1 = 0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'==i%2){
                diff1++;
            }
        }
        ret = min(ret,diff1/2);
    }

    if(n0==(n+1)/2&&n1==n/2){
        int diff2 = 0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'!=i%2){
                diff2++;
            }
        }
        ret = min(ret,diff2/2);
    }
    return ret==INT_MAX?-1:ret;
}

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    //TODO:
    }

    void add(int index, int val) {

    }

    int count(int tot) {

    }
};
int main() {
    vector<int>nums = {1,3};
    int ret = subsetXORSum(nums);
    return 0;
}