#include "bits/stdc++.h"

using namespace std;
int numFlowers(vector<vector<int>>& roads) {
    int n  = roads.size();
    vector<vector<int>>graph(n+1);
    for (int i = 0; i < roads.size(); ++i) {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);

    }
    int ret = 0;
    for (int i = 0; i < graph.size(); ++i) {
        ret = max(ret,(int)graph[i].size());
    }
    return ret+1;
}
int main() {

    return 0;
}