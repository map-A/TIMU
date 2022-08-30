//
// Created by mm on 2022/8/18.
//
#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> ret(n - 2, vector<int>(n - 2, 0));
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            int t = max({grid[i - 1][j - 1],
                         grid[i - 1][j],
                         grid[i - 1][j + 1],
                         grid[i][j - 1],
                         grid[i][j],
                         grid[i][j + 1],
                         grid[i + 1][j - 1],
                         grid[i + 1][j],
                         grid[i + 1][j + 1]});
            ret[i - 1][j - 1] = t;
        }
    }
    return ret;
}

int edgeScore(vector<int> &edges) {
    int n = edges.size();
    vector<long long> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[edges[i]] += i;
    }
    return max_element(dp.begin(), dp.end()) - dp.begin();

}

string smallestNumber(string pattern) {
    stack<int> st;;
    string ret;
    int num = 1;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == 'D') {
            // 如果为下降，则将当前数字压入栈中
            st.push(num);
        } else if (pattern[i] == 'I') {
            ret += to_string(num);
            while (!st.empty()) {
                ret += to_string(st.top());
                st.pop();
            }
        }
        num++;
    }

    st.push(num);
    while (!st.empty()) {
        ret += to_string(st.top());
        st.pop();
    }
    return ret;
}