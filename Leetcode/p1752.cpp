#include "bits/stdc++.h"

using namespace std;
bool check(vector<int>& nums) {
    if(nums.size()==1) return true;
    int l  = 0;
    int r = 0;
    int i = 1;
    for (i; i < nums.size(); ++i) {
        if(nums[i]>=nums[i-1])continue;
        else{
            break;
        }
    }
    int ll = i;
    if(i==nums.size()) return true;

    for (int i = ll+1; i < nums.size(); ++i) {
        if(nums[i]>=nums[i-1])continue;
        else{
            return false;
        }
    }
    if(nums[l]>=nums.back()){
        return true;
    }
    return false;
}
int main() {
    vector<int>v = {1,3,2};
    auto ret  = check(v);
    return 0;
}