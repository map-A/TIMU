#include "bits/stdc++.h"

using namespace std;
int openLock(vector<string>& deadends, string target) {
    //TODO: 这种做法不能出正确结果。
    int ret = INT_MAX;
    set<string>s(deadends.begin(),deadends.end());
    int dp[10][10][10][10];
    memset(dp,10,sizeof(dp));
    dp[0][0][0][0] = 0;
    dp[0][1][0][0] = 1;
    dp[0][0][1][0] = 1;
    dp[0][0][0][1] = 1;
    dp[1][0][0][0] = 1;
    for(auto i=0;i<deadends.size();i++){
        dp[deadends[i][0]-'0'][deadends[i][1]-'0'][deadends[i][2]-'0'][deadends[i][3]-'0'] = INT_MAX-1;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){

                    dp[i][j][k][l]=min(min({
                        dp[(i+1)%10][j][k][l],
                        dp[(i+9)%10][j][k][l],
                        dp[i][(j+1)%10][k][l],
                        dp[i][(j+9)%10][k][l],
                        dp[i][(j+1)%10][k][l],
                        dp[i][j][(k+1)%10][l],
                        dp[i][j][(k+9)%10][l],
                        dp[i][j][k][(l+1)%10],
                        dp[i][j][k][(l+9)%10]
                    })+1,dp[i][j][k][l]);

                }
            }
        }
    }
    return dp[target[0]-'0'][target[1]-'0'][target[2]-'0'][target[3]-'0'];
}
int main() {
    vector<string>deadpens = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    auto ret = openLock(deadpens,target);
    return 0;
}