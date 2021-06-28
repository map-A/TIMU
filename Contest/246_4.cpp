#include "bits/stdc++.h"

using namespace std;

vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<vector<int>> pre(n+1, vector<int>(101, 0));
    pre[1][nums[0]]++;
    for(int i=2;i<n+1;i++){
        pre[i] = pre[i-1];
        pre[i][nums[i-1]]++;
    }

    int m = queries.size();
    vector<int> ret(m, 0);
    for (int i = 0; i < m; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        //找l和r之间的最小值
        int minVal = INT_MAX;
        int minnum = 0;//用来做差值的
        for (int j = 1; j < 101; j++) {
            if (pre[l][j] != pre[r+1][j]) {
                if (minnum != 0) {
                    minVal = min(minVal, j - minnum);
                }
                minnum = j;
            }

        }
        if (minVal == INT_MAX) {
            minVal = -1;
        }
        ret[i] = minVal;
    }
    return ret;
}

int main() {
    vector<int> nums = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1},
                                   {1, 2},
                                   {2, 3},
                                   {0, 3}};
    auto ret = minDifference(nums,queries);
    return 0;
}