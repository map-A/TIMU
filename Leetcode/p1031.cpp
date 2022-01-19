#include "bits/stdc++.h"

using namespace std;
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    vector<int>sum = {0};
    for (int i = 0; i < nums.size(); ++i) {
        sum.push_back(sum.back()+nums[i]);
    }
    int ret = 0;
    for (int i = 0; i <= nums.size()-firstLen; ++i) {
        int sum1 = sum[i+firstLen]-sum[i];
        for (int j = 0; j+secondLen < i; ++j) {
            int sum2 = sum[j+secondLen]-sum[j];
            ret = max(ret,sum1+sum2);
        }
        for (int j = i+firstLen; j <= nums.size()-secondLen; ++j) {
            int sum2 = sum[j+secondLen]-sum[j];
            ret = max(ret,sum1+sum2);
        }
    }
    return ret;
}
int main() {
    vector<int>A = {0,6,5,2,2,5,1,9,4};
    int L=1,M=2;
    auto ret = maxSumTwoNoOverlap(A,L,M);
    return 0;
}