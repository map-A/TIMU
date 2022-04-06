#include "bits/stdc++.h"

using namespace std;
//
//int find_min_height(vector<vector<int>> &matrix, int n) {
//    int ret = 0;;
//    for (int i = 0; i < matrix.size(); i++) {
//        if (matrix[n][i] == 1) {
//            matrix[n][i] = 0;
//            matrix[i][n] = 0;
//            ret = max(ret, 1 + find_min_height(matrix, i));
//        }
//    }
//    return ret;
//}
//
//vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
//    //转换成矩阵形式
//    vector<vector<int>> matrix(n, vector<int>(n, 0));
//    for (auto edge:edges) {
//        matrix[edge[1]][edge[0]] = 1;
//        matrix[edge[0]][edge[1]] =1;
//    }
//    vector<pair<int, int>> ret;
//    int tmp = INT_MAX;
//    for (int i = 0; i < n; i++) {
//        vector<vector<int>> tmp_matrix(matrix.begin(), matrix.end());
//        tmp = find_min_height(tmp_matrix, i);
//        ret.push_back({tmp, i});
//    }
//    sort(ret.begin(), ret.end());
//    vector<int> ans = {ret[0].second};
//    for (int i = 1; i < ret.size(); i++) {
//        if (ret[i].first <= ret[0].first) {
//            ans.push_back(ret[i].second);
//        } else {
//            return ans;
//        }
//    }
//    return ans;
//}


int findLongestNode(int u, vector<int> &parent, vector<vector<int>> &adj) {
    int n = adj.size();
    queue<int> qu;
    vector<bool> visit(n);
    qu.emplace(u);
    visit[u] = true;
    int node = -1;

    while (!qu.empty()) {
        // 广度搜索
        int curr = qu.front();
        qu.pop();
        node = curr;
        for (auto &v: adj[curr]) {
            if (!visit[v]) {
                visit[v] = true;
                parent[v] = curr; //设置当前队首为他们的parent 结点
                qu.emplace(v);
            }
        }
    }
    return node;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1) {
        return {0};
    }
    vector<vector<int>> adj(n);
    for (auto &edge: edges) {
        // 转换为邻接表
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }

    vector<int> parent(n, -1);
    /* 找到与节点 0 最远的节点 x */
    int x = findLongestNode(0, parent, adj);
    /* 找到与节点 x 最远的节点 y */
    int y = findLongestNode(x, parent, adj);
    /* 求出节点 x 到节点 y 的路径 */
    vector<int> path;
    parent[x] = -1;
    while (y != -1) {
        path.emplace_back(y);
        y = parent[y];
    }
    int m = path.size();
    if (m % 2 == 0) {
        return {path[m / 2 - 1], path[m / 2]};
    } else {
        return {path[m / 2]};
    }
}


int main() {
    int n = 4;
    vector<vector<int>> edges = {{1, 0},
                                 {1, 2},
                                 {1, 3}};
    vector<int> ret = findMinHeightTrees(n, edges);
    return 0;
}