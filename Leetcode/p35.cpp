#include "bits/stdc++.h"

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    auto ret = upper_bound(nums.begin(),nums.end(),target,less<int>())-nums.begin();
    return ret;
}

int main() {

    return 0;
}