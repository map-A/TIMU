#include "bits/stdc++.h"

using namespace std;
vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int>odd;
    vector<int>even;
    for (int i = 0; i < nums.size(); ++i) {
        i%2==0?odd.push_back(nums[i]):even.push_back(nums[i]);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end(),greater<int>());
    for (int i = 0; i < nums.size(); ++i) {
        i%2==0?nums[i] = odd[i/2]:nums[i]=even[i/2];
    }
    return nums;
}
int main() {
    vector<int>nums = {4,1,2,3};
    vector<int>ret = sortEvenOdd(nums);
    return 0;
}