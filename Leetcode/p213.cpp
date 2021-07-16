#include "bits/stdc++.h"

using namespace std;

int rob(vector<int> &nums) {
    int n = nums.size();
    if (n <= 3) {
        return *max_element(nums.begin(), nums.end());
    }
    int dp1[101];
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = nums[0];
    dp1[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n - 1; i++) {
        dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
    }

    int dp2[101];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = nums[1];
    dp2[1] = max(nums[1], nums[2]);
    for (int i = 3; i < n; i++) {
        dp2[i - 1] = max(dp2[i - 3] + nums[i], dp2[i - 2]);
    }

    return max(dp1[n - 2], dp2[n - 2]);
}

int main() {
    vector<int> nums = {1, 3, 1, 3, 100};
    int ret = rob(nums);
    return 0;
}