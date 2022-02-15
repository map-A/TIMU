#include "bits/stdc++.h"

using namespace std;
void solve(vector<int>&nums){
    sort(nums.begin(),nums.end());
    int it = unique(nums.begin(),nums.end())-nums.begin();
    for (int i = 0; i < it; ++i) {
        printf("%d\n",nums[i]);
    }
}
int main() {
    int m;
    while (cin>>m){
        int n;
        vector<int>nums(m);
        for (int i = 0; i < m; ++i) {
            cin>>nums[i];
        }
        solve(nums);
    }
    return 0;
}