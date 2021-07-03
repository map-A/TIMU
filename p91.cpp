#include "bits/stdc++.h"

using namespace std;
int numDecodings(string s) {
    int n = s.size();
    if(n==0||(n==1&&s[0]=='0')) return 0;
    if(n==1) return 1;
    vector<int>dp(n+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            dp[i+1] = 0;
        }
        else{
            dp[i+1] = dp[i];
        }
        if(i>0&&(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))){
            dp[i+1] += dp[i-1];
        }
    }
    return dp[n];

}
int main() {
    string s = "226";
    int ret = numDecodings(s);
    return 0;
}