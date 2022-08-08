#include "bits/stdc++.h"

using namespace std;

double calculateTax(vector<vector<int>>& brackets, int income) {
    double ret = 0;
    for (int i = brackets.size(); i >0; --i) {
        brackets[i][0]-=brackets[i-1][0];
    }
    int i = 0;
    while (income>0){
        if(income>=brackets[i][0]){
            income-=brackets[i][0];
            ret+=brackets[i][0]*brackets[i][1]*1.0/100;
            i++;
        }
        else{
            ret+=income*brackets[i][1]*1.0/100;
            return ret;
        }
    }
    return ret;
}


int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,INT_MAX/2));
    for(int i=0;i<n;i++){
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + moveCost[grid[i - 1][k]][j]+grid[i][j]);
            }
        }
    }
    return *min_element(dp.back().begin(),dp.back().end());
}

int distributeCookies(vector<int>& cookies, int k) {
    int n = cookies.size();
    vector<int> s(1 << n);
    for (int i = 1; i < (1 << n); i++)//遍历所有的取法
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) {//按照位运算的方式，与1与，取cookie[j]
                s[i] = s[i ^ (1 << j)] + cookies[j];//s[i]是由i在位置j处相差一个1的得来的
                break;
            }
    auto f = s;
    for (int i = 1; i < k; i += 1) //有少于k个1
        for (int j = (1 << n) - 1; j; j -= 1)// 遍历每一种选择方案
            for (int l = j; l; l = (l - 1) & j)
                f[j] = min(f[j], max(f[j ^ l], s[l]));
    return f.back();
}

long long distinctNames(vector<string>& ideas) {
    unordered_set<string> ump;
    for (auto s : ideas) ump.insert(s);
    vector cnt(26, vector<int>(26));
    for (auto s : ideas) {
        int i = s[0] - 'a';
        for (int j = 0; j < 26; j += 1) {
            s[0] = 'a' + j;
            if (not ump.count(s))
                cnt[i][j] += 1;
        }
    }
    long long ans = 0;
    for (int i = 0; i < 26; i += 1)
        for (int j = 0; j < 26; j += 1)
            ans += (long long)cnt[i][j] * cnt[j][i];
    return ans;
}
int main() {

    return 0;
}