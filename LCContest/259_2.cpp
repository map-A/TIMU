#include "bits/stdc++.h"

using namespace std;
int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    vector<int>pre(n,0),suff(n,0);
    pre[0] = nums[0];
    suff[n-1] = nums[n-1];
    for(int i=1;i<n;i++){
        pre[i] = max(pre[i-1],nums[i]);
        suff[n-i-1] = min(suff[n-i],nums[n-1-i]);
    }
    for(int i=1;i+1<n;i++){
        if(nums[i]>pre[i-1]&&nums[i]<suff[i+1]){
            ret+=2;
        }
        else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1]){
            ret++;
        }
    }
    return ret;
}
int main() {

    return 0;
}