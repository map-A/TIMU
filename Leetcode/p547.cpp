#include "bits/stdc++.h"

using namespace std;
//并查集查找连通分量数目

int find(vector<int>&parent, int i)
{//并查集查找，查找i所在的子集
    if (parent[i] == -1)//表示i的parent为-1，其就是自己的祖宗
        return i;
    return find(parent, parent[i]);
}
bool Union(vector<int>&parent, int x, int y)
{//并查集的并
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset == yset)return false;
    else {
        parent[xset] = yset;
    }
    return true;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int>parent(n,-1);
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(isConnected[i][j]==1){
                Union(parent,i,j);
            }
        }
    }
    int circles = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            circles++;
        }
    }
    return circles;

}
int main() {

    vector<vector<int>>isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    int ret = findCircleNum(isConnected);
    return 0;
}