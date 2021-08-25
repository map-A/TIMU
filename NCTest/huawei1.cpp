#include "bits/stdc++.h"

using namespace std;
bool isCyclic(int v, vector<pair<bool,int>>&visited,list<vector<int>>*adj, vector<pair<bool,int>>&recStack)
{
    //recStack表示递归栈
    if (!visited[v].first)
    {
        visited[v].first = true;
        recStack[v].first = true;

        for(auto i=adj[v].begin(); i != adj[v].end();++i)
        {
            //如果节点v所连接的另一边节点i还没有被访问，
            //并且在节点i处存在环，那么真的存在环
            if(!visited[(*i)[0]].first)
            {
                visited[(*i)[0]].second+=visited[v].second;
                if(isCyclic((*i)[0], visited,adj,recStack))
                    return true;
            }
                //如果节点i已经被访问了，且在递归栈中有i，那么有环
            else if (recStack[(*i)[0]].first) {

                return true;
            }
        }
    }
    recStack[v].first = false;
    return false;
}

void solve(int num, vector<pair<int,int>>& task) {
    // pre-now-time
    list<vector<int>>* adj = new list<vector<int>>[num];
    for(int i=0;i<task.size();i++){
        adj[task[i].first].push_back({i,task[i].second});
    }

    vector<pair<bool,int>>recStack(num,{false,0});
    vector<pair<bool,int>>visited(num,{false,0});
    bool ret = true;
    for(int i=0;i<num;i++){
        if(!visited[i].first) ret&=!(isCyclic(i, visited, adj, recStack));
    }
    cout<<ret;
}



//int main() {
//    int n;
//    cin>>n;
//    vector<pair<int,int>>task(n);//pre-time
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d %d\n",&task[i].first,&task[i].second);
//    }
//    solve(task,n);
//    return 0;
//}



vector<pair<int, int>> directs = {{-1, 0},
                                  {1,  0},
                                  {0,  1},
                                  {0,  -1}};

int dfs(int m, int n, vector<vector<int>> &vis, vector<vector<int>> &grid,int sum) {
    int row = grid.size();
    int col = grid[0].size();
    vis[m][n] = 1;
    if(m==row-1&&n==col-1){
        cout<<sum;
        return 0;
    }
    for (auto i:directs) {
        int x = m + i.first;
        int y = n + i.second;
        if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] >=sum && vis[x][y] == 0) {
            sum+=1;
            dfs(x, y, vis, grid,sum);
            sum-=1;
        }
    }
}


void solve(vector<vector<int>>&grid){
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>>vis(row,vector<int>(col,0));
    int sum = 0;
    int ret = dfs(0,0,vis,grid,sum);
    if(ret!=0)cout<<-1;
}

int main(void){
    int m,n;
    scanf("%d %d\n",&m,&n);
    vector<vector<int>>grid(m);
    string line;
    string temp;
    //每次读取一整行
    int i=0;
    for(int i=0;i<m;i++){
        string line;
        getline(cin,line);
        string tmp;
        stringstream ss(line);
        while(getline(ss, tmp, ' ')){
            grid[i].push_back(stoi(tmp));
        }
    }
    solve(grid);
}
