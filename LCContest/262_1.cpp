#include "bits/stdc++.h"

using namespace std;

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    const int len = 101;
    int nums[len];
    memset(nums,0, sizeof(nums));
    sort(nums1.begin(), nums1.end());
    auto i1 = unique(nums1.begin(),nums1.end());
    nums1.erase(i1,nums1.end());
    for(auto i:nums1){
        nums[i]++;
    }
    sort(nums2.begin(), nums2.end());
    auto i2 = unique(nums2.begin(),nums2.end());
    nums2.erase(i2,nums2.end());
    for(auto i:nums2){
        nums[i]++;
    }

    sort(nums3.begin(), nums3.end());
    auto i3 = unique(nums3.begin(),nums3.end());
    nums3.erase(i3,nums3.end());
    for(auto i:nums3){
        nums[i]++;
    }
    vector<int>ret;
    for (int i = 0; i < len; ++i) {
        if(nums[i]>=2){
            ret.push_back(i);
        }
    }
    return ret;
}
int main() {
    vector<int>nums1 = {1,1,3,2};
    vector<int>nums2 = {2,3};
    vector<int>nums3 = {3};
    auto ret = twoOutOfThree(nums1,nums2,nums3);
    return 0;
}