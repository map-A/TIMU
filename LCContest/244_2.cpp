#include "bits/stdc++.h"

using namespace std;
int reductionOperations(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int ret = 0;
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            cnt++;//发现有多少个不同的元素
        }
        ret+=cnt;
    }
    return ret;
}

int main() {
    vector<int>nums={1,1,2,3,2};
    int ret = reductionOperations(nums);

    return 0;
}