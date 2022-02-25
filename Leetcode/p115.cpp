#include "bits/stdc++.h"

using namespace std;
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(2,vector<int>(n+1,0));
    for (int i = 0; i < n+1; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            if(t[i-1]==s[j-1]){
                dp[1][j] = dp[0][j-1]+dp[1][j-1];
            }
            else{
                dp[1][j] = dp[1][j-1];
            }
        }
        dp[0] = dp[1];
    }
    return dp[1][n-1];

}
int main() {
    string s = "rabbbit",t = "rabbit";
    int ret = numDistinct(s,t);
    return 0;
}