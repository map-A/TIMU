#include "bits/stdc++.h"

using namespace std;
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size(), cnt = 0;
    vector<int> res;
    for (int i = 0; i < k; ++i) cnt += nums[i] == key;
    for (int i = 0; i < n; ++i) {
        if (i > k && nums[i - k - 1] == key) --cnt;
        if (i + k < n && nums[i + k] == key) ++cnt;
        if (cnt > 0) res.push_back(i);
    }
    return res;
}


int maximumTop(vector<int>& nums, int k) {
    if(nums.size()==1&&(k&1)) return -1;

    int mx = *max_element(nums.begin(),nums.begin()+min(k+1,(int)nums.size()));
    if(k<nums.size()){
        mx = max(mx,nums[k]);
    }
    return mx;
}

int main() {

    return 0;
}