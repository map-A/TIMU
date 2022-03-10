#include "bits/stdc++.h"

using namespace std;


void bfs(int S, vector<vector<int>> &my_e, vector<vector<int>> &ret) {
    vector<bool> vis(my_e.size(), false);
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while (!q.empty()) {
        int sn = q.front();
        q.pop();
        for (int fn: my_e[sn])
            if (!vis[fn]) {
                vis[fn] = true;
                q.push(fn);
                ret[fn].push_back(S);
            }
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> ret = vector<vector<int>>(n);
    vector<vector<int>> my_e = vector<vector<int>>(n);
    vector<bool> vis(n, false);

    for (auto &edge: edges) {
        my_e[edge[0]].push_back(edge[1]);
    }
    for (int i = 0; i < n; i++) {
        bfs(i, my_e, ret);
    }
    return ret;
}

int main() {

    return 0;
}