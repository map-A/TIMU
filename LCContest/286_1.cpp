#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int>ret1,ret2;
    for (int i = 0; i < nums1.size(); ++i) {
        bool flag = true;
        for (int j = 0; j <nums2.size() ; ++j) {
            if(nums1[i]==nums2[j]){
                flag  = false;
                break;
            }
        }
        if(flag) ret1.push_back(nums1[i]);
    }
    sort(ret1.begin(),ret1.end());
    auto i = unique(ret1.begin(),ret1.end())-ret1.begin();
    for (int i = 0; i < nums2.size(); ++i) {
        bool flag = true;
        for (int j = 0; j <nums1.size() ; ++j) {
            if(nums2[i]==nums1[j]){
                flag  = false;
                break;
            }
        }
        if(flag) ret2.push_back(nums2[i]);
    }
    sort(ret2.begin(),ret2.end());
    auto j = unique(ret2.begin(),ret2.end())-ret2.begin();
    return {vector<int>(ret1.begin(),ret1.begin()+i),vector<int>(ret2.begin(),ret2.begin()+j)};


}
int main() {

    return 0;
}