#include "bits/stdc++.h"

using namespace std;
int countHillValley(vector<int>& nums) {
    vector<int> v;
    for (int x : nums)
        //去重
        if (v.empty() or v.back() != x) v.push_back(x);
    int res = 0;
    for (int i = 1; i + 1 < v.size(); i += 1) {
        res += (v[i] - v[i - 1]) * (v[i] - v[i + 1]) > 0;
    }
    return res;
}
int main() {
    vector<int>nums = {2,4,1,1,6,5};
    int ret = countHillValley(nums);
    return 0;
}