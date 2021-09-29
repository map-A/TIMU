#include "bits/stdc++.h"

using namespace std;
long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<vector<long long>>pre_sum(2,vector<long long>(n+2,0));

    for(int i=0;i<n;i++){
        pre_sum[1][i+1] = pre_sum[1][i]+grid[1][i];
        pre_sum[0][n-i] =pre_sum[0][n-i+1]+grid[0][n-i-1];
    }
    long long max_2 = LONG_MAX;

    for(int i=1;i<=n;i++){ //找到机器人一的最大值
        max_2 = min(max(pre_sum[0][i+1],pre_sum[1][i-1]),max_2);
    }
    return max_2;

}
int main() {
    vector<vector<int>> grid ={{2,5,4},{1,5,1}};
    auto ret = gridGame(grid);
    return 0;
}