#include "bits/stdc++.h"

using namespace std;
int diff(vector<int>&nums)
{
    int len = nums.size();

    long long sum = std::accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp;
    for (int i = 0; i <= len; i++) {
        vector<int>tmp;
        for (int j = 0; j <= sum / 2; ++j) {
            tmp.push_back(0);
        }
        dp.push_back(tmp);
    }

    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= sum / 2; ++j) {
            if(j>=nums[i-1])dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i-1]]+nums[i-1]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    return (int)(sum - 2*dp[len][sum / 2]);
}


int main() {
    vector<int> num;
    string line;
    string temp;
    getline(cin, line);
    stringstream ss(line);
    while (getline(ss, temp, ' ')) {
        num.push_back(stoi(temp));
    }
    int ret = diff(num);
    return 0;
}