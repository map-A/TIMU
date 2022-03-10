#include "bits/stdc++.h"

using namespace std;

// 按照数字间的间隔消耗k
long long minimalKSum(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    long long ret = 0;
    int j = 1;
    for (int i = 0; i < nums.size()&&k; ++i) {
        if(nums[i]-j>0){
            int d = min(k,nums[i]-j);
            ret+=(long long)(j+j+d-1)*d/2;
            k-=d;
        }
        j = nums[i]+1;
    }
    if(k){
        ret +=(long long )(j+j+k-1)*k/2;
    }
    return ret;
}
int main() {

    return 0;
}