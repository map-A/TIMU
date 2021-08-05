#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int N = edges.size();
    vector<int>parent(N+1,-1);
    int count =0;
    for(int i=0; i<N; ++i){
        if(!Union(parent,edges[i][0],edges[i][1]))
            break;
        count++;
    }
    return edges[count];

}

int find(vector<int>&parent, int i)
{//并查集查找，查找i所在的子集
    if (parent[i] == -1)
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

int main() {
    return 0;
}
