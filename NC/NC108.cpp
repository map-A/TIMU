#include "bits/stdc++.h"

using namespace std;
int solve(vector<vector<char> >& matrix) {
    int m = matrix.size(),n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    int ret = INT_MIN;
    for(int i=0;i<m;i++){
        dp[i][0] = matrix[i][0]-'0';
        ret =max(ret,dp[i][0]);
    }
    for(int i=0;i<n;i++){
        dp[0][i] = matrix[0][i]-'0';
        ret =max(ret,dp[0][i]);
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]=='1')
                dp[i][j] =min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
            ret =max(ret,dp[i][j]);
        }
    }
    return ret*ret;
}
int main() {

    return 0;
}