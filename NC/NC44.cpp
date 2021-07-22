#include "bits/stdc++.h"

using namespace std;


bool isMatch(const char *s, const char *p) {
    int m = strlen(s);
    int n = strlen(p);
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for(int i=1;i<=m;i++){
        dp[i][0] =true;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' && (dp[i - 1][j] || dp[i][j - 1])) {
                dp[i][j] = true;
            } else {
                if (p[j - 1] == '?' && dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                } else if (p[j - 1] == s[i - 1] && dp[i - 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}