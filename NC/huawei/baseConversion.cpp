#include "bits/stdc++.h"

using namespace std;
void solve(string s){
    int ret = 0;
    for (int i = 2; i < s.size(); ++i) {
        if(isdigit(s[i])){
            ret = ret*16+s[i]-'0';
        }
        if(isalpha(s[i])){
            ret = ret*16+ 10+(s[i]-'A');
        }
    }
    printf("%d\n",ret);
}
int main() {
    string s;
    while (cin>>s){
        solve(s);
    }
    return 0;
}