#include "bits/stdc++.h"

using namespace std;
vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<char>>& board,int x,int y,vector<vector<int>>&vis,set<pair<int,int>>&t){
    int m = board.size();
    int n = board[0].size();
    vis[x][y] = 1;
    t.insert({x,y});
    for (int i = 0; i < dir.size(); ++i) {
        int new_x = x+dir[i].first;
        int new_y = y+dir[i].second;
        if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&vis[new_x][new_y]==0&&board[new_x][new_y]=='O'){
            dfs(board,new_x,new_y,vis,t);
        }
    }
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    set<pair<int,int>>ops;
    set<pair<int,int>>t;
    if(m<3||n<3) return ;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(board[i][j]=='O') ops.insert({i,j});
        }
    }
    vector<vector<int>>vis(m,vector<int>(n,0));
    for (int i = 0; i < n; ++i) {
        //第一行
        if(board[0][i]=='O'&&vis[0][i]!=1){
            dfs(board,0,i,vis,t);
        }
    }
    for (int i = 0; i < n; ++i) {
        //最后一行
        if(board[m-1][i]=='O'&&vis[m-1][i]!=1){
            dfs(board,m-1,i,vis,t);
        }
    }
    for (int i = 0; i < m; ++i) {
        //第一列
        if(board[i][0]=='O'&&vis[i][0]!=1){
            dfs(board,i,0,vis,t);
        }
    }
    for (int i = 0; i < m; ++i) {
        //最后一列
        if(board[i][n-1]=='O'&&vis[i][n-1]!=1){
            dfs(board,i,n-1,vis,t);
        }
    }
    set<pair<int,int>>ret;
    std::set_difference(ops.begin(), ops.end(), t.begin(),t.end(), inserter(ret,ret.begin()));
    for(auto i:ret){
        board[i.first][i.second]='X';
    }
}
int main() {
    vector<vector<char>>board ={
            {'X','O','X','O','X','O'},
            {'O','X','O','X','O','X'},
            {'X','O','X','O','X','O'},
            {'O','X','O','X','O','X'}};
    solve(board);
    return 0;
}