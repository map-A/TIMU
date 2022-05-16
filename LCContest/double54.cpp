#include "bits/stdc++.h"

using namespace std;

bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    vector<int>vis(51,0);
    for(int i=0;i<ranges.size();i++){
        for(int j=ranges[i][0];j<=ranges[i][1];j++){
            vis[j] = 1;
        }
    }
    for(int j=left;j<=right;j++){
        if(vis[j]==0) return false;
    }
    return true;
}


//https://blog.csdn.net/qq_41221520/article/details/108277801
int binarySearchFirstLessEqual(vector<long long> vec, int target) {
    int l = 0, r = vec.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] > target)  //关键点,>
        {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (r < 0)  //如果要找的是最后一个等于target的位置，则条件是 if(r<0 || vec[r]!=target)
        return -1;
    return r;
}

int chalkReplacer(vector<int> &chalk, int k) {
    int n = chalk.size();

    vector<long long> sum(n, 0);
    sum[0] = chalk[0];
    for (int i = 1; i < chalk.size(); i++) {
        sum[i] = sum[i - 1] + chalk[i];
    }
    long long r = binarySearchFirstLessEqual(sum, k);
    int ret = (r + 1 + n) % n;
    while (r == n - 1) {
        k %= sum[r];
        r = binarySearchFirstLessEqual(sum, k);
        ret = (r + 1 + n) % n;
        //cout<<r;
    }
    return ret;
}

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
    vector<vector<int>> range = {{1, 2},
                                 {3, 4},
                                 {5, 6}};
    int left = 2, right = 5;
    bool ret = isCovered(range, left, right);
    return 0;
}