#include "bits/stdc++.h"

using namespace std;
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    int ret = 0;
    vector<vector<int>>vis(m,vector<int>(n,0));
    for (int i = 0; i < walls.size(); ++i) {
        vis[walls[i][0]][walls[i][1]]=2;//此处有墙；
    }
    for (int i = 0; i < guards.size(); ++i) {
        vis[guards[i][0]][guards[i][1]]=1;//此处有人；
    }
    vector<pair<int,int>>direct = {{0,1},{0,-1},{1,0},{-1,0}};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //此处有一个保安
            if(vis[i][j]==1){
                //开始向四周看去
                for(auto &dir:direct){
                    int new_x=i,new_y = j;
                    while (new_x>=0&&new_x<m&&new_y>=0&&new_y<n){
                        new_x = new_x+dir.first;
                        new_y = new_y+dir.second;
                        if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&(vis[new_x][new_y]==0||vis[new_x][new_y]==-1)){
                            vis[new_x][new_y]=-1;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(vis[i][j]==0){
                ret++;
            }
        }

    }
    return ret;
}
int main() {
    int m = 4,n=6;
    vector<vector<int>>guards ={{0,0},{1,1},{2,3}};
    vector<vector<int>>wall = {{0,1},{2,2},{1,4}};
    int ret =  countUnguarded(m,n,guards,wall);
    return 0;
}