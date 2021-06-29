#include "bits/stdc++.h"

using namespace std;
int largestMagicSquare(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>rowSum(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            rowSum[i][j]=rowSum[i][j-1]+grid[i-1][j-1];
        }
    }

    vector<vector<int>>colSum(m+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           colSum[j][i]=colSum[j-1][i]+grid[j-1][i-1];
        }
    }
    for(int i=min(m,n);i>1;i--){
        //检查大小为i是否为幻方
        //枚举各个位置的幻方
        for(int j=1;j<=m+1-i;j++){
            for(int k=1;k<=n+1-i;k++){
                //检查从jk开始，大小为i的幻方
                int tmp = rowSum[j][i-1+k] -rowSum[j][k-1];
                bool flag = true;
                for(int l=j;l<j+i;l++){
                    if(tmp!=rowSum[l][i-1+k]-rowSum[l][k-1]){
                        flag= false;
                        break;
                    }
                }
                if(flag){
                    for(int l=k;l<k+i;l++){
                        if(tmp!=colSum[j+i-1][l]-colSum[j-1][l]){
                            flag= false;
                            break;
                        }
                    }
                }
                if(flag){
                    //判断两个对角线
                     int sumxie=0;
                    for(int l=0;l<i;l++){
                        sumxie+=grid[j-1+l][k-1+l];
                    }
                    if(tmp!=sumxie){
                        flag = false;
                        continue;
                    }
                    sumxie = 0;
                    for(int l=0;l<i;l++){
                        sumxie+=grid[j-1+l][k+i-2-l];
                    }
                    if(tmp!=sumxie){
                        flag = false;
                        continue;
                    }
                }
                if(flag) return i;

            }
        }
    }
    return 1;
}



int main() {
    vector<vector<int>> grid = {{1,2,1,1},{2,1,1,1},{3,2,2,3},{1,3,3,3}};
    int ret = largestMagicSquare(grid);

    return 0;
}