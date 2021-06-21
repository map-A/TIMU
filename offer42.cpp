#include "bits/stdc++.h"

using namespace std;


int FindGreatestSumOfSubArray1(vector<int> array) {
    int ret = INT_MIN;
    for (int i = 0; i < array.size(); i++) {
        int sum = 0;
        for (int j = i; j < array.size(); j++) {
            sum += array[j];
            ret = max(ret, sum);
        }
    }
    return ret;
}

int FindGreatestSumOfSubArray(vector<int> &array) {
    vector<int> dp(array.size(), 0);
    dp[0] = array[0];
    int ret = dp[0];
    for (int i = 1; i < array.size(); i++) {
        dp[i] = max(dp[i - 1] + array[i], array[i]);
        ret = max(ret, dp[i]);
    }

    return ret;
}

int maxSubArray(vector<int> &array) {
    int dp = array[0];
    int ret = dp;
    for (int i = 1; i < array.size(); i++) {
        dp = max(dp + array[i], array[i]);
        ret = max(ret, dp);
    }
    return ret;
}


int main() {
    vector<int> array = {1, -2, 3, 10, -4, 7, 2, -5};
    int ret = FindGreatestSumOfSubArray(array);
    return 0;
}