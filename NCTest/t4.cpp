#include "bits/stdc++.h"

using namespace std;
bool solve(vector<int>& nums, int k) {
    int n=nums.size();
    if(n%k!=0) return false;
    sort(nums.begin(), nums.end());
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) m[nums[i]]++;
    for(int i=0;i<n;i++)
    {
        if(m[nums[i]]==0) continue;
        for(int j=0;j<k;j++)
        {
            if(m.count(nums[i]+j)==0) return false;
            map[nums[i]+j]--;
        }
    }
    return true;

}

int main() {

    return 0;
}