#include "bits/stdc++.h"

using namespace std;
vector<pair<int,int>>directs = {{0,1},{1,0},{0,-1},
                                {-1,0}};
int ret = 0;
int countZero = 0;
void backtrace(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&vis,int nums){
    //nums表示回溯了多少次
    int row = grid.size(),col = grid[0].size();
    for(auto i:directs){
        int x = m+i.first;
        int y = n+i.second;
        if(x>=0&&x<row&&y>=0&&y<col&&vis[x][y]==0&&grid[x][y]==0){
            vis[x][y] = 1;
            backtrace(x,y,grid,vis,nums+1);
            vis[x][y] = 0;
        }
        if(x>=0&&x<row&&y>=0&&y<col&&vis[x][y]==0&&grid[x][y]==2){
            if(countZero==nums){
                ret+=1;
                return;
            }
        }
    }

}
int uniquePathsIII(vector<vector<int>>& grid) {
    int row = grid.size(),col = grid[0].size();
    vector<vector<int>>vis(row,vector<int>(col,0));

    int startx = 0,starty = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                startx = i;
                starty = j;
            }
            else if(grid[i][j]==0){
                countZero++;
            }
        }
    }
    vis[startx][starty]=1;
    backtrace(startx,starty,grid,vis,0);
    return ret;
}

int main() {
    vector<vector<int>>grid = {{0,0,0,0,0,0,2,0,0,0},{0,0,0,0,0,0,0,0,1,0}};
    int ret = uniquePathsIII(grid);
    return 0;
}