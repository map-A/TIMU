#include "bits/stdc++.h"

using namespace std;
int numberOfSubstrings(string s) {
    int ret = 0;
    map<char,int>m;
    int l = 0;
    int r = 0;
    for (int i = 0; i < s.size(); ++i) {
        m[s[i]]++;
        if(m.size()==3){
            r=i;
            break;
        }
    }
    for (l; l< s.size();l++) {
        if(m.size()==3){
            ret+=s.size()-r;
            m[s[l]]--;
            if(m[s[l]]==0)m.erase(s[l]);
        }
        while(m.size()<3&&r<s.size()-1)m[s[++r]]++;
    }
    return ret;
}
int main() {
    string s = "bcabac";
    int ret = numberOfSubstrings(s);

    return 0;
}