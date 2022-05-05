#include "bits/stdc++.h"

using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0 || k == 1) return 0;
    int l = 0;
    int prod = 1; //存储nums[l]~nums[r]的累积
    int res = 0;
    for(int r = 0; r < nums.size(); r++){
        prod *= nums[r];
        while(prod >= k){
            prod /= nums[l];
            l++;
        }
        res += r - l + 1;
    }
    return res;
}
int main() {

    return 0;
}