#include "bits/stdc++.h"

using namespace std;
string removeOccurrences(string s, string part) {
    size_t pos = s.find(part);
    string tmp = s;
    while(pos!=std::string::npos){
        tmp =tmp.replace(pos,part.size(),"");
        pos = tmp.find(part);
    }
    return tmp;
}
int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    auto ret = removeOccurrences(s,part);
    return 0;
}