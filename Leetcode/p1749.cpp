#include "bits/stdc++.h"

using namespace std;

int maxAbsoluteSum(vector<int> &nums) {
    int n = nums.size();
    int max_ret = INT_MIN;
    int min_ret = INT_MAX;
    vector<int> max_dp(n + 1, INT_MIN / 2);
    vector<int> min_dp(n + 1, INT_MAX / 2);
    for (int i = 1; i <= n; ++i) {
        max_dp[i] = max(nums[i-1], max_dp[i - 1] + nums[i - 1]);
        min_dp[i] = min(nums[i-1], min_dp[i - 1] + nums[i - 1]);
        max_ret = max(max_dp[i], max_ret);
        min_ret = min(min_dp[i], min_ret);
    }
    return max(abs(max_ret), abs(min_ret));

}

int main() {

    return 0;
}