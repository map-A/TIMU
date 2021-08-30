#include "bits/stdc++.h"

using namespace std;
int minimumDifference(vector<int>& nums, int k) {
    if(k==1) return 0;
    int ret = INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i=0;i+k-1<nums.size();i++){
        ret = min(ret,nums[i+k-1]-nums[i]);
    }
    return ret;

}
int main() {

    return 0;
}