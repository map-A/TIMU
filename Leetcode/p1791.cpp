#include "bits/stdc++.h"

using namespace std;

int findCenter(vector<vector<int>>& edges) {
    const int N=1e5+1;
    int degree[N];
    memset(degree,0,sizeof(degree));
    int n = 0;
    for(int i=0;i<edges.size();i++){
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        n = max({n,edges[i][0],edges[i][1]});
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==n-1) return i;
    }
    return 0;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}