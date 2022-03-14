#include "bits/stdc++.h"

using namespace std;
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size(), cnt = 0;
    vector<int> res;
    for (int i = 0; i < k; ++i) cnt += nums[i] == key;
    for (int i = 0; i < n; ++i) {
        if (i > k && nums[i - k - 1] == key) --cnt;
        if (i + k < n && nums[i + k] == key) ++cnt;
        if (cnt > 0) res.push_back(i);
    }
    return res;
}
int main() {

    return 0;
}