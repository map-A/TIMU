#include "bits/stdc++.h"

using namespace std;
int maximumTop(vector<int>& nums, int k) {
    if(nums.size()==1&&(k&1)) return -1;

    int mx = *max_element(nums.begin(),nums.begin()+min(k+1,(int)nums.size()));
    if(k<nums.size()){
        mx = max(mx,nums[k]);
    }
    return mx;
}
int main() {

    return 0;
}