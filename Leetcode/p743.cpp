#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> floydWarshall(vector<vector<int >> &path) {
    int n = path.size();
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX/2));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = path[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INT_MAX/2  && dist[i][k] != INT_MAX/2))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}


int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<int>>graph(n,vector<int>(n,INT_MAX/2));
    for(auto i:times){
        graph[i[0]-1][i[1]-1]  = i[2];
    }
    auto cost = floydWarshall(graph);
    int ret = 0;
    for(auto i:cost[k-1]){
        if(i!=INT_MAX/2){
            ret = max(i,ret);
        }
        else{
            return -1;
        }
    }
    return ret==0?-1:ret;
}
int main() {

    return 0;
}