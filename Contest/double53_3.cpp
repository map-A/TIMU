#include "bits/stdc++.h"

using namespace std;

vector<int> putNum(vector<int> &a, int num) {
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        //先找一遍有没有重复元素
        if (a[i] == num) {
            return a;
        }
    }
    if (a[0] < num) {
        a[0] = num;
        return a;
    }
    return a;
}

vector<int> getBiggestThree(vector<vector<int>> &grid) {
    vector<int> ret(3, 0);
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //以ij为中心，长度
            int len = min({i, j, m - 1 - i, n - 1 - j});
            for (int k = 0; k <= len; k++) {
                //求长度为k，以ij为中心元素和
                int sum = 0;
                if (k == 0) {
                    sum = grid[i][j];
                } else {
                    //加上棱形线上面的元素
                    for(int x=i,y=j-k;x<i+k&&y<j;x++,y++){
                        sum+=grid[x][y];
                    }
                    for(int x = i+k,y=j;x>i&&y<j+k;x--,y++){
                        sum+=grid[x][y];
                    }
                    for(int x=i,y=j+k;x>i-k&&y>j;x--,y--){
                        sum+=grid[x][y];
                    }
                    for(int x=i-k,y=j;x<i&&y>j-k;x++,y--){
                        sum+=grid[x][y];
                    }

                }
                putNum(ret, sum);
            }
        }
    }
    sort(ret.begin(), ret.end(), greater<int>());
    vector<int> finalret;
    for (auto i:ret) {
        if (i != 0) {
            finalret.push_back(i);
        }
    }
    return finalret;
}

int main() {
    vector<vector<int>> grid = {{20, 17, 9,  13, 5,  2,  9,  1,  5},
                                {14, 9,  9,  9,  16, 18, 3,  4,  12},
                                {18, 15, 10, 20, 19, 20, 15, 12, 11},
                                {19, 16, 19, 18, 8,  13, 15, 14, 11},
                                {4,  19, 5,  2,  19, 17, 7,  2,  2}};
    vector<int> ret = getBiggestThree(grid);
    return 0;
}