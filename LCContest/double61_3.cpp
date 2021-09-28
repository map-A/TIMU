#include "bits/stdc++.h"

using namespace std;

static bool cmp(vector<int> & v1, vector<int> & v2) {
    return v1[0] < v2[0];
}
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end(), cmp);
    vector<long long> dp(n+1,0);  // 在i的位置最多可以赚多少
    int start = 0;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i], dp[i + 1]);
        if(start != rides.size()&& rides[start][0] == i) { // 在这个地方有人可以接
            dp[rides[start][1]] = max(dp[rides[start][1]], dp[i] + rides[start][2] + rides[start][1] - rides[start][0]);
            start++;
            i--;
        }

    }
    return dp[n];
}



int main() {

    return 0;
}