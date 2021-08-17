#include "bits/stdc++.h"

using namespace std;

vector<string> summaryRanges(vector<int> &nums) {
    if (nums.empty()) return {};
    sort(nums.begin(), nums.end());
    vector<string> ret;
    int l = nums[0];
    int r = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != r + 1) {
            if (l == r) {
                ret.push_back(to_string(r));
            } else {
                ret.push_back({to_string(l) + "->" + to_string(r)});
            }
            l = nums[i];
        }
        r = nums[i];
    }
    if (l == r) {
        ret.push_back(to_string(r));
    } else {
        ret.push_back({to_string(l) + "->" + to_string(r)});
    }
    return ret;
}

int main() {

    return 0;
}