#include "bits/stdc++.h"

using namespace std;

map<char,int>m;
int help(){
    int ret = 0;
    int max_num = 0;
    for (auto &i:m) {
        max_num = max(max_num,i.second);
        ret+=i.second;
    }
    return ret-max_num;
}
int characterReplacement(string s, int k) {
    int l=0,r=0;
    int ret = 0;
    for (; l < s.size();) {
        if(help()>k){
            m[s[l]]--;
            l++;
        }
        while (help()<=k){
            ret = max(ret,r-l);
            if(r<s.size())m[s[r]]++;
            if(r==s.size()) return max(ret,r-l);

            r++;
        }
    }
    return ret;
}
int main() {
    int k = 0;
    string s = "ABAA";
    int ret = characterReplacement(s,k);
    return 0;
}