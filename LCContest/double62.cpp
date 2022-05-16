#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if(m*n!=original.size()){
        return {};
    }
    vector<vector<int>>ret(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ret[i][j] = original[i*n+j];
        }
    }
    return ret;
}



int numOfPairs(vector<string>& nums, string target) {
    int n = nums.size();
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(target==nums[i]+nums[j]){
                ret++;
            }
            if(target==nums[j]+nums[i]){
                ret++;
            }
        }
    }
    return ret;
}


int maxConsecutiveAnswers(string ans, int k) {
    int n = ans.size();
    int l = 0;
    int r = 0;
    int tNums = 0;
    int fNums = 0;
    while (r < n) {
        if (ans[r] == 'T') {
            tNums++;
        } else {
            fNums++;
        }
        int mx = max(tNums, fNums);
        if (r - l + 1 - mx > k) {
            if (ans[l] == 'T') {
                tNums--;
            } else {
                fNums--;
            }
            ++l;
        }
        ++r;
    }
    return r - l;
}



int main() {
    vector<int>original = {1,2,3,4};
    auto ret = construct2DArray(original,2,2);

    return 0;
}