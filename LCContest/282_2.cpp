#include "bits/stdc++.h"

using namespace std;
int minSteps(string s, string t) {
    int ret = 0;
    if(s==t) return  ret;
    vector<int>alpha1(26,0);
    vector<int>alpha2(26,0);

    for (int i = 0; i < s.size(); ++i) {
        alpha1[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
        alpha2[t[i]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        ret+= abs(alpha1[i]-alpha2[i]);
    }
    return ret;
}
int main() {
    string s = "cotxazilut",t = "nahrrmcchxwrieqqdwdpneitkxgnt";
    int ret = minSteps(s,t);
    return 0;
}