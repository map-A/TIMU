#include "bits/stdc++.h"

using namespace std;
int maximumDifference(vector<int>& nums) {
    int ret = -1;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            ret = max(nums[j]-nums[i],ret);
        }
    }
    return ret==0?-1:ret;
}
int main() {

    return 0;
}