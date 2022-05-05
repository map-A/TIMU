#include "bits/stdc++.h"

using namespace std;
int minimumAverageDifference(vector<int>& nums) {
    long long sum = std::accumulate(nums.begin(), nums.end(), (long long)0);
    long long  l_sum = 0;
    int ans = 0;
    long long ret = LLONG_MAX;

    for (int i = 0; i <nums.size()-1 ; ++i) {
        l_sum+=(long long)nums[i];
        long long  t  = l_sum/(i+1)-(sum-l_sum)/(nums.size()-i-1);
        //cout<<ret;
        if(t<=0) t = -1*t;
        if(ret>t){
            ret =t;
            ans = i;
        }
    }
    if(ret>sum/nums.size()){
        ans = nums.size()-1;
    }
    return ans;
}
int main() {
    vector<int>nums = {0,0,3};
    int ret = minimumAverageDifference(nums);
    return 0;
}