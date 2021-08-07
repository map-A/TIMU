#include "bits/stdc++.h"

using namespace std;
vector<vector<int>>ret;

//寻找路径
void findPath(vector<vector<int>>&graph,int v,vector<int>&path){
    path.push_back(v);
    if(v==graph.size()-1) ret.push_back(path);
    for(auto i: graph[v]) findPath(graph,i,path);
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int>path;
    findPath(graph,0,path);
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}