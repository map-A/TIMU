#include "bits/stdc++.h"

using namespace std;
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size(),n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    priority_queue<int,vector<int>>pq;
    dp[0][0] = matrix[0][0];
    pq.push(dp[0][0]);
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i-1]^matrix[0][i];
        pq.push(dp[0][i]);
    }
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0]^matrix[i][0];
        pq.push(dp[i][0]);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j]^dp[i][j-1]^matrix[i][j]^dp[i-1][j-1];
            pq.push(dp[i][j]);
        }
    }
    while (k>1){
        pq.pop();
        k--;
    }
    return pq.top();

}
int main() {
    vector<vector<int>>matrix = {{5,2},{1,6}};
    int k = 1;
    int ret = kthLargestValue(matrix,k);
    return 0;
}