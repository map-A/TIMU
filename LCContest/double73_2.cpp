#include "bits/stdc++.h"

using namespace std;

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int,int>>t(nums.size());
    for (int i = 0; i <nums.size() ; ++i) {
        string new_string = to_string(nums[i]);
        for (int i = 0; i < new_string.size(); ++i) {
            new_string[i] = '0'+(mapping[new_string[i]-'0']);
        }
        t[i] = {stoi(new_string), i};
    }
    sort(t.begin(),t.end());
    vector<int>ret(nums.size());
    for(int i = 0;i<nums.size();i++){
        ret[i] = nums[t[i].second];
    }
    return ret;
}
int main() {
    vector<int>mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int>nums = {991,338,38};
    auto ret = sortJumbled(mapping,nums);
    return 0;
}