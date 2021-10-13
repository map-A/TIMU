#include "bits/stdc++.h"

using namespace std;
int numOfPairs(vector<string>& nums, string target) {
    int n = nums.size();
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(target==nums[i]+nums[j]){
                ret++;
            }
            if(target==nums[j]+nums[i]){
                ret++;
            }
        }
    }
    return ret;
}
int main() {

    return 0;
}