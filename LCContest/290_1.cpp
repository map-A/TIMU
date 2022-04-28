#include "bits/stdc++.h"

using namespace std;
vector<int> intersection(vector<vector<int>>& nums) {
    vector<int>bucket(1001,0);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            bucket[nums[i][j]]++;
        }
    }
    vector<int>ret;
    for (int i = 0; i < bucket.size(); ++i) {
        if(bucket[i]>=(int)nums.size()){
            ret.push_back(i);
        }
    }
    return ret;
}
int main() {

    return 0;
}