#include "bits/stdc++.h"

using namespace std;
int countPairs(vector<int>& nums, int k) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if(nums[i]==nums[j]&&(i*j%k==0))
                ret++;
        }
    }
    return ret;
}
int main() {

    return 0;
}