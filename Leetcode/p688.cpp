#include "bits/stdc++.h"

using namespace std;
double knightProbability(int n, int k, int row, int column) {
    double dp[101][26][26];
    vector<vector<int>>direct = {{1,2},{1,-2},{-1,2},{-1,-2},
                                 {2,1},{2,-1},{-2,1},{-2,-1}};
    queue<pair<int,int>>q;
    set<pair<int,int>>s;
    q.push({row,column});
    s.insert({row,column});
    memset(dp, 0, sizeof(dp));
    dp[0][row][column] = 1;

    for (int i = 1; i <= k; ++i) {
        int len = q.size();
        s.clear();
        for (int j = 0; j < len; ++j) {
            auto t = q.front();
            q.pop();
            for (int m = 0; m < direct.size(); ++m) {
                int x = t.first + direct[m][0];
                int y = t.second+ direct[m][1];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    if(s.find({x,y})==s.end()){
                        q.push({x,y});
                        s.insert({x,y});
                    }
                    dp[i][x][y] += (1.0 / 8 * dp[i - 1][t.first][t.second]);
                }
            }
        }

    }
    double ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ret+=dp[k][i][j];
        }
    }
    return ret;
}
int main() {
    int n = 3,k=3,row = 0,column = 0;
    double ret = knightProbability(n,k,row,column);
    return 0;
}