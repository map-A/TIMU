#include "bits/stdc++.h"

using namespace std;
string optimalDivision(vector<int> &nums) {
    if (nums.size() == 1)       //注意考虑size为1和2的特殊情况
        return  to_string(nums[0]);
    if (nums.size() == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    string re(to_string(nums[0]) + "/(");
    for (int i = 1; i < nums.size() - 1; ++i) {
        re += to_string(nums[i]) + "/";
    }
    re += to_string(nums.back()) + ")";     //最后一个数 和括号
    return re;
}
int main() {

    return 0;
}