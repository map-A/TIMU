#include "bits/stdc++.h"

using namespace std;
vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> ret(n, pivot);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < pivot) {
            ret[left++] = nums[i];
        }
        else if (nums[i] > pivot) {
            ret[right--] = nums[i];
        }
    }
    reverse(ret.begin() + right + 1, ret.end());
    return ret;
}
int main() {

    return 0;
}