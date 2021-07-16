#include "bits/stdc++.h"

using namespace std;

int find_min_height(vector<vector<int>> &matrix, int n) {
    int ret = 0;;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[n][i] == 1) {
            matrix[n][i] = 0;
            matrix[i][n] = 0;
            ret = max(ret, 1 + find_min_height(matrix, i));
        }
    }
    return ret;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    //转换成矩阵形式
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (auto edge:edges) {
        matrix[edge[1]][edge[0]] = 1;
        matrix[edge[0]][edge[1]] =1;
    }
    vector<pair<int, int>> ret;
    int tmp = INT_MAX;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> tmp_matrix(matrix.begin(), matrix.end());
        tmp = find_min_height(tmp_matrix, i);
        ret.push_back({tmp, i});
    }
    sort(ret.begin(), ret.end());
    vector<int> ans = {ret[0].second};
    for (int i = 1; i < ret.size(); i++) {
        if (ret[i].first <= ret[0].first) {
            ans.push_back(ret[i].second);
        } else {
            return ans;
        }
    }
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{1, 0},
                                 {1, 2},
                                 {1, 3}};
    vector<int> ret = findMinHeightTrees(n, edges);
    return 0;
}