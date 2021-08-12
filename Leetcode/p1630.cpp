#include "bits/stdc++.h"

using namespace std;
bool check(vector<int>&nums,int l,int r){
    vector<int>tmp(nums.begin()+l,nums.begin()+r+1);
    sort(tmp.begin(),tmp.end());
    for(int i=1;i<tmp.size()-1;i++){
        if(2*tmp[i]!=tmp[i-1]+tmp[i+1]){
            return false;
        }
    }
    return true;
}
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int len = l.size();
    vector<bool>ret(len);
    for(int i=0;i<len;i++){
        ret[i] = check(nums,l[i],r[i]);
    }
    return ret;
}
int main() {

    return 0;
}