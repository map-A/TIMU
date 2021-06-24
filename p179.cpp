#include "bits/stdc++.h"

using namespace std;

string largestNumber(vector<int> &nums) {
    vector<string> tmp;
    for (auto i:nums) {
        tmp.push_back(to_string(i));
    }
    sort(tmp.begin(), tmp.end(), greater<string>());
    string ret;
    for (auto &i:tmp) {
        ret += i;
    }
    return ret;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    auto ret = largestNumber(nums);
    return 0;
}