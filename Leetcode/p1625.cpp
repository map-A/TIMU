#include "bits/stdc++.h"

using namespace std;
string add(string s,int a){
    string ret(s);
    for (int i = 1; i <s.size(); i+=2) {
        ret[i]= '0'+(ret[i]-'0'+a)%10;
    }
    return ret;
}
string rotata(string s,int b){
    string ret(s);
    rotate(ret.begin(),ret.begin()+b,ret.end());
    return ret;
}
string findLexSmallestString(string s, int a, int b) {
    set<string>set1;
    string ret(s);
    queue<string>q;
    q.push(s);
    while(!q.empty()){
        string ss = q.front();
        q.pop();
        string t = add(ss,a);
        ret = min(ret,t);
        if(set1.find(t)==set1.end()){
            set1.insert(t);
            q.push(t);
        }
        t = rotata(ss,b);
        ret = min(ret,t);
        if(set1.find(t)==set1.end()){
            set1.insert(t);
            q.push(t);
        }
    }
    return ret;
}
int main() {
    string s = "74";
    int a=5,b=1;
    string ret = findLexSmallestString(s,a,b);
    return 0;
}