#include "bits/stdc++.h"

using namespace std;
int f[100010];
const int mod = 1e9+7;
int countTexts(string s) {
    int n = s.size();
    f[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=4; j++) {
            if(i-j<0)
                break;
            if(s[i-j]!=s[i-1])
                break;
            if(j==4 && s[i-1]!='7' && s[i-1]!='9')
                break;
            f[i] += f[i-j];
            f[i] %= mod;
        }
    }
    return f[n];
}
int main() {

    return 0;
}