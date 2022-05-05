#include "bits/stdc++.h"

using namespace std;
int countDistinct(vector<int>& nums, int k, int p) {
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        vector<int> t;
        /* 区间[i,j], 满足最多k个可整除元素, 加入set中 */
        for (int j = i; j < n; j++) {
            t.push_back(nums[j]);
            if (nums[j] % p == 0) {
                cnt++;
            }
            if (cnt <= k) { /* 可整除的元素个数不大于k */
                st.insert(t);
            } else {
                break;
            }
        }
    }
    return st.size();
}
int main() {

    return 0;
}