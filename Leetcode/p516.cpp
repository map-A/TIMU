#include "bits/stdc++.h"

using namespace std;
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>>dp(n,vector<int>(n,1));
    for(int i=2;i<n+1;i++){
        for(int j=0;j<n-i+1;j++){
            int k = i+j-1;
            if(s[j]==s[k]&&i==2)dp[j][k]=2;
            else if(s[j]==s[k])dp[j][k] = dp[j+1][k-1]+2;
            else dp[j][k] = max(dp[j][k-1],dp[j+1][k]);
        }
    }
    return dp[0][n-1];

}
int main() {

    return 0;
}