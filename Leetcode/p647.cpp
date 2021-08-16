#include "bits/stdc++.h"

using namespace std;
//回文子串的个数
int countSubstrings(string s) {
    int n = s.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    //当两个索引重复，一定是回文的
    for(int i=0;i<n;i++)dp[i][i]=1;
    int ret = n;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            //当两个索引距离为1，相同时为回文
            if(i-j==1&&s[i]==s[j])dp[i][j]=1;
            //当[j+1]-[i-1]是回文的话，并且两端相等
            if(dp[i-1][j+1]==1&&s[i]==s[j])dp[i][j]=1;
            ret+=dp[i][j];
        }
    }
    return ret;
}
int main() {

    return 0;
}