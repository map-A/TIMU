#include "bits/stdc++.h"

using namespace std;
bool diff(string s,string t){
    if(s.size()!=t.size()) return false;
    int ret = 0;
    for (int i = 0; i < t.size(); ++i) {
        if(s[i]!=t[i]) ret++;
    }
    return ret==1;
}
int countSubstrings(string s, string t) {
    int ret = 0;
    for (int i = 0; i < t.size(); ++i) {
        for (int j = i+1; j <= t.size(); ++j) {
            string sub_t = t.substr(i,j-i);
            for (int k = 0; k < s.size(); ++k) {
                for (int l = k+sub_t.size(); l <= s.size(); ++l) {
                    string sub_s = s.substr(k,l-k);
                    if(sub_s.size()>sub_t.size())break;
                    if(diff(sub_s,sub_t))ret++;
                }
            }
        }
    }
    return ret;
}
int main() {
    string s = "aba";
    string t = "baba";
    auto ret = countSubstrings(s,t);
    return 0;
}