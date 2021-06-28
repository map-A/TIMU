#include "bits/stdc++.h"

using namespace std;
int maxProductDifference(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n-1]*nums[n-2]-(nums[0]*nums[1]);
}
int main() {
   vector<int>nums ={ 4,2,5,9,7,4,8};
    int ret = maxProductDifference(nums);
    return 0;
}