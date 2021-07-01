#include "bits/stdc++.h"

using namespace std;

int numWays(int n, vector<vector<int>> &relation, int k) {
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < relation.size(); j++) {
            dp[i][relation[j][1]] += dp[i - 1][relation[j][0]];
        }
    }
    return dp[k][n - 1];
}

int main() {
    int n = 5, k = 3;
    vector<vector<int>> relations = {{0, 2},
                                     {2, 1},
                                     {3, 4},
                                     {2, 3},
                                     {1, 4},
                                     {2, 0},
                                     {0, 4}};
    int ret = numWays(n, relations, k);
    return 0;
}