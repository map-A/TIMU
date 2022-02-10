#include "bits/stdc++.h"

using namespace std;
int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>>dp(n,vector<int>(2*n,0));
    int M = 1;
    vector<int>sum(n,piles.back());
    for (int i = n; i >1; --i) {
        sum[i-2] = sum[i-1]+piles[i-2];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int M = 1; M <= n; M++) {
            if (i + 2 * M >= n) {
                dp[i][M] = sum[i];
            }
            else {
                for (int x = 1; x <= 2 * M; x++) {
                    dp[i][M] = max(dp[i][M], sum[i] - dp[i + x][max(M, x)]);
                }
            }
        }
    }
    return dp[0][1];

}
int main() {
    vector<int>piles = {2,7,9,4,4};
    int ret = stoneGameII(piles);
    return 0;
}