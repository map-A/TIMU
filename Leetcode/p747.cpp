#include "bits/stdc++.h"

using namespace std;
int dominantIndex(vector<int>& nums) {
    int maxnum = max_element(nums.begin(), nums.end())-nums.begin();
    vector<int>::iterator a = min_element(nums.begin(),nums.end());
    int result = maxnum;
    for(int i = 0; i < nums.size();i++){
        if(i == maxnum) {
            continue;
        }
        if(nums[i] * 2 > nums[maxnum]) {
            result = -1;
            break;
        }
    }
    return result;
}
int main() {
    vector<int>v = {1,2,3,4};
    int ret = dominantIndex(v);

    return 0;
}