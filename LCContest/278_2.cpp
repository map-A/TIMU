#include "bits/stdc++.h"

using namespace std;
vector<int> maxScoreIndices(vector<int>& nums) {
    int l = 0;
    int r = 0;
    for (int i = nums.size()-1; i >=0 ; --i) {
        r+=nums[i];
    }
    int sum = l+r;
    vector<int>ret = {0};
    for (int i = 0; i < nums.size(); ++i) {
        l+=(1-nums[i]);
        r-=nums[i];
        if(l+r==sum){
            ret.push_back(i+1);
        }
        else if(l+r>sum){
            sum = l+r;
            ret.clear();
            ret.push_back(i+1);
        }
    }
    return ret;
}
int main() {
    vector<int>nums = {0,0,1,0};
    auto ret = maxScoreIndices(nums);
    return 0;
}