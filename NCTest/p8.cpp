#include "bits/stdc++.h"

using namespace std;
vector<int> flag;
bool check(vector<int> &nums, int k, int r, int target, int cur) {
    if (k == 1) return true;
    if (cur == target) return check(nums, k - 1, nums.size() - 1, target, 0);
    for (int i = r; i >= 0; --i) {
        if (flag[i] == 1) continue;
        if (cur + nums[i] > target) continue;
        flag[i] = 1;
        if (check(nums, k, i - 1, target, cur + nums[i])) return true;
        flag[i] = 0;
        while (i > 0 && nums[i] == nums[i - 1]) --i;
    }
    return false;
}
bool canPartitionKSubsets(vector<int> &nums, int k) {
    if (k == 1) return true;
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    flag.resize(n);
    if (sum % k || nums[n - 1] > sum / k) return false;
    int target = sum / k;
    return check(nums, k, n - 1, target, 0);

}
int solve(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int min_ele = *min_element(nums.begin(), nums.end());
    for (int i = min_ele; i > 0; i--) {
        if (canPartitionKSubsets(nums, i)) {
            return i;
        }
    }
    return 1;
}


int main() {
    vector<int> nums = {12, 8, 17, 12, 5, 20};
    int ret = solve(nums);
    return 0;
}