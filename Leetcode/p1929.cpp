#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int>ret(nums.begin(),nums.end());
    ret.insert(ret.end(),nums.begin(),nums.end());
    return ret;
}

int main() {
    vector<int>nums = {1,2,1};
    auto ret = getConcatenation(nums);
    return 0;
}
