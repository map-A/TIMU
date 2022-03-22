#include "bits/stdc++.h"

using namespace std;


int slove(string s){
    map<char,int>m;
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        m[s[i]]++;
    }
    for (auto i:m) {
        ret+=(i.second/2)-i.second%2;
    }
    return ret;
}
int main() {
    int n;
    scanf("%d\n",&n);
    string s;
    cin>>s;
    int ret = slove(s);
    return 0;
}