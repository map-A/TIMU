#include "bits/stdc++.h"

using namespace std;
int sumBase(int n, int k) {
    int ans = 0 ;
    while(n){
        ans += n % k;
        n /= k;
    }
    return ans;
}


int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    long long total =0;
    int ret = 1;

    int l = 0;
    for (int r = 1; r < n; ++r) {
        total += (long long)(nums[r] - nums[r - l]) * (r - l);
        while (total > k) {
            total -= nums[r] - nums[l];
            ++l;
        }
        ret = max(ret, r - l + 1);
    }
    return ret;
}
int main() {

    return 0;
}