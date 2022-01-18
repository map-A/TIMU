#include "bits/stdc++.h"

using namespace std;
vector<string> divideString(string s, int k, char fill) {
    vector<string>ret;
    int i = 0;
    for(i;i<s.size();i+=k){
        if(i+k<=s.size())
        ret.push_back(s.substr(i,k));
    }
    if(i==s.size()) return ret;
    else{
        string last = s.substr(i-k);
        string t(k-last.size(),fill);
        last+=t;
        ret.push_back(last);
        return ret;
    }
    return {};
}
int main() {
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    auto ret = divideString(s,k,fill);
    return 0;
}