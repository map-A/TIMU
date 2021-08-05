#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<bool>visited(numCourses,false);
    stack<int>s;
    vector<vector<int>>pre(numCourses);
    vector<int>ret;
    vector<bool>restack(numCourses,false);
    for(auto prerequisiy:prerequisites){
        pre[prerequisiy[1]].push_back(prerequisiy[0]);
    }
    int V = numCourses;
    for(int i = 0; i < V; i++)//对于每个节点，若没有被访问过，都要进行拓扑排序
        if (visited[i] == false)
            topologicalSortUtil(i, visited, s,pre,restack);
    while (s.empty() == false){
        ret.push_back(s.top());
        s.pop();
    }
    if(ret.size()!=numCourses)return {};
    return ret;


}
void topologicalSortUtil(int v,vector<bool>&visited,stack<int> &Stack,vector<vector<int>>&adj,vector<bool>&restack)
{
    visited[v] = true;
    restack[v] = true;
    for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i]) topologicalSortUtil(*i, visited, Stack,adj,restack);
        else if(restack[*i]){
            while(!Stack.empty())Stack.pop();
            return ;
        }
    restack[v] = false;
    Stack.push(v);
}

int main() {
    return 0;
}
