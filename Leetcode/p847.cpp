#include "bits/stdc++.h"

using namespace std;

//寻找遍历图的所有结点的最短路径，可重复，非那个np问题
int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    queue<tuple<int,int,int>>q; //node number-mask,present the node is whether visited-length
    vector<vector<int>>vis(n,vector<int>(1<<n));
    //状态数组，以数字第i位是否为1表示结点i是否被访问了,vis[v]=mask
    for(int i=0;i<n;++i){
        q.emplace(i,1<<i,0);
        vis[i][1<<i] = true;
    }
    int ret = 0;
    //此时q以所有结点为初始结点的情况，
    while(!q.empty()){
        auto [u,mask,dist] = q.front();
        q.pop();
        if(mask==(1<<n)-1){
            //当mask所有位都为1，表示所有结点都已经访问了，
            ret = dist;
            break;
        }
        for(int v:graph[u]){
            //u为当前的起始点,将mask的第v位设置为1
            int mask_v = mask|(1<<v);
            if(!vis[v][mask_v]){
                q.emplace(v,mask_v,dist+1);
                vis[v][mask] = true;
            }
        }
    }
    return ret;
}
int main() {

    return 0;
}