#include "bits/stdc++.h"

using namespace std;
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int total = nums[0];
    vector<int>ret;
    int tmp;
    for(int i=1;i<nums.size();++i){
        tmp =total%(int)pow(2,maximumBit);
        ret.push_back(tmp^(int)(pow(2,maximumBit)-1));
        total = total^nums[i];
    }
    tmp =total%(int)pow(2,maximumBit);
    ret.push_back(tmp^(int)(pow(2,maximumBit)-1));
    reverse(ret.begin(),ret.end());
    return ret;
}
int main() {

    return 0;
}