#include "bits/stdc++.h"

using namespace std;
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(),n = s2.size();
    if(s3.size()!=m+n){
        return false;
    }
    vector<vector<bool>>dp(m+1,vector<bool>(n+1,0));
    dp[0][0]=true;
    for(int i=1;i<=m;i++){
        dp[i][0] = (dp[i-1][0]&&(s1[i-1]==s3[i-1]));
    }
    for(int i=1;i<=n;i++){
        dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j]||(dp[i][j-1]&&(s3[i+j-1]==s2[j-1]));
            dp[i][j]=dp[i][j]||(dp[i-1][j]&&(s3[i+j-1]==s1[i-1]));
        }
    }
    return dp[m][n];
}
int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    bool ret = isInterleave(s1,s2,s3);
    return 0;
}