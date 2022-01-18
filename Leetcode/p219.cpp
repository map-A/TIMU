#include "bits/stdc++.h"

using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int,vector<int>>m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]].push_back(i);
    }
    for(auto i:m){
        if(i.second.size()>2){
            int max_abs=0;
            for(int j=0;j<i.second.size()-1;j++){
                max_abs = max(max_abs,abs(i.second[j+1]-i.second[j]));
            }
            if(max_abs<=k) return true;
        }
    }
    return false;
}
int main() {

    return 0;
}