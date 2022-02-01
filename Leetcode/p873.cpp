#include "bits/stdc++.h"

using namespace std;
int lenLongestFibSubseq(vector<int>& arr) {
    int len = arr.size();
    unordered_map<int,int>m;
    for (int i = 0; i < len; ++i) {
        m[arr[i]]=i;
    }
    int ret = 0;
    vector<vector<int>>dp(len,vector<int>(len,2));
    for (int i = 2; i < len; ++i) {
        for (int j = i-1; j >0 ; j--) {
            int diff = arr[i]-arr[j];
            if(m.count(diff)&&j>m[diff]){
                dp[i][j] = dp[j][m[diff]]+1;
            }
            ret= max(ret,dp[i][j]);
        }
    }
    return ret==2?0:ret;
}
int main() {

    return 0;
}