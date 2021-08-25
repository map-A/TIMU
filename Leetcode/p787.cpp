#include "bits/stdc++.h"
using namespace std;


vector<vector<pair<int,int>>> floydWarshall(vector<vector<int >> &path) {
    int n = path.size();
    vector<vector<pair<int,int>>> dist(n,vector<pair<int,int>>(n,{LLONG_MAX/2,0}));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j].first = path[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dist[i][i] = {0,0};
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j].first > (dist[i][k].first + dist[k][j].first)
                    && (dist[k][j].first != LLONG_MAX/2  && dist[i][k].first     != LLONG_MAX/2)){
                    dist[i][j].first = dist[i][k].first + dist[k][j].first;
                    dist[i][j].second =  dist[i][k].second + dist[k][j].second+1;
                }

            }
        }
    }
    return dist;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>path(n,vector<int>(n,INT_MAX/2));
        for(auto i:flights){
            path[i[0]][i[1]] = i[2];
        }
        auto ret = floydWarshall(path);
        if(ret[src][dst].first==INT_MAX/2&&(ret[src][dst].second<=k))
        {
            return -1;
        }
        else{
            return ret[src][dst].second;
        }
    }
int main() {

    return 0;
}