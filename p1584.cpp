#include "bits/stdc++.h"

using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=110;
bool vis[MAXN];
int lowc[MAXN];
int minCostConnectPoints(vector<vector<int>>& points) {

    int m=points.size();
    vector<vector<int>>graph(m,vector<int>(m,0));
    for(int i=0;i<m;++i){
        for(int j=0;j<m;j++){
            graph[i][j] = abs(points[i][0]-points[j][0])+
                    abs(points[i][1]-points[j][1]);
        }
    }

    int ret = 0;
    memset(vis, false,sizeof(vis));
    vis[0]=true;
    for(int i=0;i<m;i++){
        lowc[i] = graph[0][i];
    }
    for(int i=1;i<m;i++){
        int minC = INT_MAX;
        int p=-1;
        for(int j=0;j<m;j++){
             if(!vis[j]&&minC>lowc[j]){
                 minC = lowc[j];
                 p=j;
             }
        }
        if(minC==INT_MAX) return -1;
        ret+=minC;
        vis[p] = true;
        for(int j=0;j<m;j++){
            if(!vis[j]&&lowc[j]>graph[p][j]){
                lowc[j] = graph[p][j];
            }
        }
    }
    return ret;

}
int main() {
    vector<vector<int>>points = {{3,12},{-2,5},{-4,1}};
    int ret = minCostConnectPoints(points);
    return 0;
}