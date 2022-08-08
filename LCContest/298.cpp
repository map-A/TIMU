#include "bits/stdc++.h"

using namespace std;
string greatestLetter(string s) {
    vector<vector<int>>dp(26,vector<int>(2,0));
    for (int i = 0; i < s.size(); ++i) {
        if(islower(s[i])){
           dp[s[i]-'a'][0]=1;
        }
        if(isupper(s[i])){
            dp[s[i]-'A'][1]=1;
        }
    }
    for (int i = 25; i >=0; --i) {
        if(dp[i][0]+dp[i][1]==2){
            return string(1, toupper('A'+i));
        }
    }
    return "";
}

int minimumNumbers(int num, int k) {
    if(num==0) return 0;
    for(int i=1;i<=10;i++){
        if(i*k%10==num%10&&num>=k*i){
            //可能存在方案
            return i;
        }
    }
    return -1;
}

int longestSubsequence(string s, int k) {
    //求的是子序列，不是子串
    int n = s.length(), m = 32 - __builtin_clz(k);//k的实际位数，从1开始
    if (n < m) return n;
    int ret = 0;
    //最后m位对应的二进制数值，小于则取m位，大于丢掉一位，然后尽可能的添加前n-m中的0
    if(stoi(s.substr(n - m), nullptr, 2) <= k){
        ret = m;
    }
    else{
        ret = m-1;
    }
    return ret + count(s.begin(), s.end() - m, '0');
}






int main() {

    return 0;
}