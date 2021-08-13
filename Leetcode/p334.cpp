#include "bits/stdc++.h"

using namespace std;
bool increasingTriplet(vector<int>& nums) {
    if(nums.size()<3) return false;
    int a = INT_MAX,b = INT_MAX;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]<a){
            a = nums[i];
        }
        else if(nums[i]>a&&nums[i]<b){
            b = nums[i];
        }
        else if(nums[i]>b&&nums[i]>a){
            return true;
        }
    }
    return false;
}
int main() {

    return 0;
}