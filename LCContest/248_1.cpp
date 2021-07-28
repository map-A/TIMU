#include "bits/stdc++.h"

using namespace std;
vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    vector<int>ret(n);
    for(int i=0;i<n;i++){
        ret[i] = nums[nums[i]];
    }
    return ret;
}
int main() {


    return 0;
}