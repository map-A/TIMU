#include "bits/stdc++.h"

using namespace std;
int mostFrequent(vector<int>& nums, int key) {
    vector<int>ret(1001,0);
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] == key) {
            ret[nums[i + 1]]++;
        }
    }

    return max_element(ret.begin(),ret.end())-ret.begin();
}
int main() {
    vector<int>nums = {1,100,200,1,100};
    int key = 1;
    int ret = mostFrequent(nums,key);
    return 0;
}