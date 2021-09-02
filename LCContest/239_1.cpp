#include "bits/stdc++.h"

using namespace std;
int getMinDistance(vector<int>& nums, int target, int start) {
    int ret = INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            ret = min(ret,abs(start-i));
        }
    }
    return ret;
}
int main() {

    return 0;
}