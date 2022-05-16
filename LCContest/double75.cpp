#include "bits/stdc++.h"

using namespace std;
int minBitFlips(int start, int goal) {
    int t = start^goal;
    int ret = 0;
    while (t>0){
        ret+=t&1;
        t = t>>1;
    }
    return ret;
}


int triangularSum(vector<int>& nums) {
    int t = nums.size();
    while (t>1){
        for (int i = 0; i <t-1; ++i) {
            nums[i] = (nums[i]+nums[i+1])%10;
        }
        t-=1;
    }
    return nums[0];
}


long long combination(string s, string t) {
    //niubi
    long long a = 0, b = 0, c = 0;
    for (char x: s) {
        if (x == t[2]) c += b;// 统计t[0]t[1]t[2]一起出现组合的次数
        if (x == t[1]) b += a;// 统计t[0]t[1]一起出现组合的次数
        if (x == t[0]) a += 1;// 统计t[0]字符出现的次数
    }
    return c;
}

long long numberOfWays(string s) {
    return combination(s, "101") + combination(s, "010");
}

long long sumScores(string s) {
    int n = s.length();
    long ans = n;
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        z[i] = max(min(z[i - l], r - i + 1), 0);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i];
            ++z[i];
        }
        ans += z[i];
    }
    return ans;
}


int main() {
    int start  =10,goal = 7;
    int ret = minBitFlips(start,goal);
    return 0;
}


