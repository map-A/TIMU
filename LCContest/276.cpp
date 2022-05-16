#include "bits/stdc++.h"

using namespace std;
vector<string> divideString(string s, int k, char fill) {
    vector<string>ret;
    int i = 0;
    for(i;i<s.size();i+=k){
        if(i+k<=s.size())
        ret.push_back(s.substr(i,k));
    }
    if(i==s.size()) return ret;
    else{
        string last = s.substr(i-k);
        string t(k-last.size(),fill);
        last+=t;
        ret.push_back(last);
        return ret;
    }
    return {};
}

int minMoves(int target, int maxDoubles) {
    int ret = 0;
    while (target>1){
        if(target%2!=0){
            target--;
            ret++;
        }
        else{
            if(maxDoubles>0){
                maxDoubles--;
                ret++;
                ret/=2;
            }
            else{
                ret+=(target-1);
                target=1;
            }
        }
    }
    return ret;
}



long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    // dp[i] 表示解决区间 [i, n-1] 内的问题可以获得的最高分数
    vector<int>dp(n+1);
    for (int i = n - 1; i >= 0; i--) {
        int j = i + questions[i][1] + 1;
        dp[i] = max(dp[i + 1], questions[i][0] + (j < n ? dp[j] : 0));
    }
    return dp[0];
}



int main() {
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    auto ret = divideString(s,k,fill);
    return 0;
}