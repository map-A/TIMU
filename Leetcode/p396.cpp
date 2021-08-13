#include "bits/stdc++.h"

using namespace std;

int maxRotateFunction(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * nums[i];
    }
    int t = accumulate(nums.begin(), nums.end(), 0);
    vector<int> dp(n);
    dp[0] = sum;
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = dp[i - 1] + t - n * nums[n - i];
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {

    return 0;
}