#include "bits/stdc++.h"

using namespace std;
// 将数字分配到桶里，然后找出桶内的最大值和最小值

int maximumGap(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    int d = max(1, (maxVal - minVal) / (n - 1)); // 每个桶间个
    int bucketSize = (maxVal - minVal) / d + 1; // 桶的大小

    vector<pair<int, int>> bucket(bucketSize, {INT_MAX, INT_MIN});  // 存储 (桶内最小值，桶内最大值) 对，(-1, -1) 表示该桶是空的
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - minVal) / d;
            bucket[idx].first = min(bucket[idx].first, nums[i]);
            bucket[idx].second = max(bucket[idx].second, nums[i]);
    }

    int ret = 0;
    int prev = -1;
    for (int i = 0; i < bucketSize; i++) {
        if (bucket[i].first == INT_MAX) continue;
        if (prev != -1) {
            ret = max(ret, bucket[i].first - bucket[prev].second);
        }
        prev = i;
    }
    return ret;
}


int main() {

    return 0;
}