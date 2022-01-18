#include "bits/stdc++.h"

using namespace std;
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    // dp[i] 表示解决区间 [i, n-1] 内的问题可以获得的最高分数
    vector<int>dp(n+1);
    for (int i = n - 1; i >= 0; i--) {
        int j = i + questions[i][1] + 1;
        dp[i] = max(dp[i + 1], questions[i][0] + (j < n ? dp[j] : 0));
    }
    return dp[0];
}
int main() {

    return 0;
}