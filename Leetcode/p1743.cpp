#include "bits/stdc++.h"

using namespace std;

vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, vector<int>> mp;
    for (auto &adjacentPair: adjacentPairs) {
        mp[adjacentPair[0]].push_back(adjacentPair[1]);
        mp[adjacentPair[1]].push_back(adjacentPair[0]);
    }

    int n = adjacentPairs.size() + 1;
    vector<int> ret(n);
    for (auto&[e, adj] : mp) {
        if (adj.size() == 1) {
            ret[0] = e;
            break;
        }
    }
    ret[1] = mp[ret[0]][0];
    for (int i = 2; i < n; i++) {
        auto &adj = mp[ret[i - 1]];
        if (ret[i - 2] == adj[0]) {
            ret[i] = adj[1];
        } else {
            ret[i] = adj[0];
        }
    }
    return ret;
}

int main() {

    return 0;
}