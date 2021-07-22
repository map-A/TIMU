#include "bits/stdc++.h"

using namespace std;

int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    int m = str1.length(),n = str2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i==0) {
                dp[i][j] =j*ic;
            }
            else if(j==0){
                dp[i][j]=i*dc;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min({dp[i-1][j]+dc,dp[i-1][j-1]+rc,dp[i][j-1]+ic});
            }
        }
    }
    return dp[m][n];
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}