#include "bits/stdc++.h"

using namespace std;

// 删除字符串使得字符串变好
string makeFancyString(string s) {
    if(s.size()<3) return s;
    string ret;
    char a = s[0];
    char  b = s[1];
    ret+=a;
    ret+=b;
    for(int i=2;i<s.size();i++){
        if(a==b&&b==s[i]){
            int c;
        }
        else{
            ret+=s[i];
        }
        a = b;
        b = s[i];
    }
    return ret;
}
int main() {
    string s = "leeetcxode";
    string ret = makeFancyString(s);
    return 0;
}