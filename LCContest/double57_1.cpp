#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

bool areOccurrencesEqual(string s) {
    int ch[26]={0};
    //memset(ch,0,26);
    for (int i=0;i<s.size();i++){
        ch[s[i]-'a']++;
    }
    int cnt = 0;
    for (int i : ch){
        if(i!=0&&cnt==0){
            cnt = i;
        }
       if(i!=0&&cnt!=i) return false;
    }
    return true;
}

int main() {
    string s = "abacbc";
    bool ret = areOccurrencesEqual(s);
    return 0;
}
