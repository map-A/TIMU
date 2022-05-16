#include "bits/stdc++.h"

using namespace std;

// 删除字符串使得字符串变好
string makeFancyString(string s) {
    if(s.size()<3) return s;
    string ret;
    char a = s[0];
    char  b = s[1];
    ret+=a;
    ret+=b;
    for(int i=2;i<s.size();i++){
        if(a==b&&b==s[i]){
            int c;
        }
        else{
            ret+=s[i];
        }
        a = b;
        b = s[i];
    }
    return ret;
}



bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
    //横方向，左边

    vector<vector<int>> directs = {{-1, 0},
                                   {1,  0},
                                   {0,  -1},
                                   {0,  1},
                                   {-1, -1},
                                   {1,  -1},
                                   {-1, 1},
                                   {1,  1}};

    //左，右，上，下，左上，右上，左下，右下
    for (auto direct :directs) {
        int x = rMove, y = cMove;
        int flag = false;
        while (x + direct[1] >= 0 && x + direct[1] < 8 && y + direct[0] >= 0 && y + direct[0] < 8) {
            x = x + direct[1];
            y = y + direct[0];
            if (board[x][y] != color && board[x][y] != '.') {
                flag = true;
            } else if (board[x][y] == color && flag) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}



int minSpaceWastedKResizing(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        int best = INT_MIN;
        int total = 0;
        for(int j=i;j<n;j++){
            best = max(best,nums[j]);//i-j之间的最大值
            total +=nums[j];//i-j之间的数和
            g[i][j] = best*(j-i+1)-total;
        }
    }
    vector<vector<int>>dp(n,vector<int>(k+2,INT_MAX/2));
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=k+1;j++){
            for(int k=0;k<=i;k++){
                dp[i][j] = min(dp[i][j],(k==0?0:dp[k-1][j-1])+g[k][i]);
            }
        }
    }
    return dp[n-1][k+1];
}


int main() {
    string s = "leeetcxode";
    string ret = makeFancyString(s);
    return 0;
}