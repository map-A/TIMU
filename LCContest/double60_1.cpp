#include "bits/stdc++.h"

using namespace std;
int findMiddleIndex(vector<int>& nums) {
    int l = 0, r = 0, idx = 0;
    for (int num : nums) {
        r += num;
    }
    while (idx < nums.size()) {
        r -= nums[idx];
        if (l == r) {
            return idx;
        }
        l += nums[idx++];
    }
    return -1;
}
int main() {

    return 0;
}