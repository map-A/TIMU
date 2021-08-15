#include "bits/stdc++.h"

using namespace std;
vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> ret(nums.size());
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1, i = 0;
    while (l <= r){
        if (i % 2 == 0) ret[i++] = nums[l++];
        else ret[i++] = nums[r--];
    }
    return ret;
}
int main() {

    return 0;
}