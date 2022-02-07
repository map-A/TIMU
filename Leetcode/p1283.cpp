#include "bits/stdc++.h"

using namespace std;

int help(vector<int>&nums,int t){
    int ret = 0;
    for(auto &i:nums){
        ret+=(int)ceil(i*1.0/t);
    }
    return ret;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    sort(nums.begin(),nums.end());

    int l=1,r = nums.back();
    while (l<r){
        int mid = (r-l)/2+l;
        int t = help(nums,mid);
        if(t<=threshold){
           r =mid;
        }
        else{
            l = mid+1;
        }
    }
    return r;
}
int main() {
    vector<int>nums = {2,3,5,7,11};
    int threshold =11;
    int ret = smallestDivisor(nums,threshold);
    return 0;
}