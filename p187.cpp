#include "bits/stdc++.h"

using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<char,int>m = {{'A',0},{'C',1},{'G',2},{'T',3}};
    vector<string>ret;
    bitset<1<<20>s1,s2;
    int val = 0;
    int mask = (1<<20)-1;
    for(int i=0;i<10;i++){
        val = (val<<2)|m[s[i]];
    }
    s1.set(val);
    for(int i=10;i<s.size();i++){
        val = ((val<<2)&mask)|m[s[i]];
        //去掉左边字符。并且加上右边的字符
        if(s2.test(val)){
            continue;
        }
        if(s1.test(val)){
            ret.push_back(s.substr(i-9,10));
            s2.set(val);
        }
        else{
            s1.set(val);
        }
    }
    return ret;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}