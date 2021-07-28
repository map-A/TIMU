#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

void solve() {

    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    if (m < n) {
        cout<< 0;
    }
    vector<vector<long>> dp(m + 1, vector<long>(n + 1));
    for (int i = 0; i <= m; i++) {
        dp[i][n] = 1;
    }
    for (int i = m - 1; i >= 0; i--) {
        char sChar = s.at(i);
        for (int j = n - 1; j >= 0; j--) {
            char tChar = t.at(j);
            if (sChar == tChar) {
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }
    cout<<dp[0][0];
}

int main() {
    int T = -1;
    cin>>T;
    while(T--){
        solve();
    }
}
