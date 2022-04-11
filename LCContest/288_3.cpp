#include "bits/stdc++.h"

using namespace std;
int maximumProduct(vector<int>& nums, int k) {
    // auto q = priority_queue{greater{}, move(nums)};
    priority_queue<int,vector<int>,greater<int>>pq;
    for (int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);
    }
    while(k>0){
        --k;
        int tmp = pq.top()+1;
        pq.pop();
        pq.push(tmp);
    }
    long long ret = 1;
    for (auto i:(vector<int>&)pq) {
        ret*=i;
        ret = ret%1000000007;

    }
    return ret;

}
int main() {
    vector<int>nums = {6,3,3,2};
    int k = 2;
    int ret = maximumProduct(nums,k);
    return 0;
}