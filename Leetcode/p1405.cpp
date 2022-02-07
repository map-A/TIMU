#include "bits/stdc++.h"

using namespace std;
typedef pair<char,int> pp;
static bool cmp(pp i, pp j) { return i.second > j.second; }
string longestDiverseString(int a, int b, int c) {
    vector<pp> v = {{'a',a},{'b',b},{'c',c}};
    sort(v.begin(),v.end(),cmp);
    string s = "";
    while(v[1].second>0){
        if(v[0].second>(v[1].second+v[2].second)){
            s.insert(s.end(),2,v[0].first);
            v[0].second-=2;
            if(v[1].second>0){
                s.insert(s.end(),1,v[1].first);
                v[1].second-=1;
            }

        }
        else{
            if(v[0].second>0){
                s.insert(s.end(),1,v[0].first);
                v[0].second-=1;
            }
            if(v[1].second>0){
                s.insert(s.end(),1,v[1].first);
                v[1].second-=1;
            }
        }
        sort(v.begin(),v.end(),cmp);
    }
    sort(v.begin(),v.end(),cmp);
    if(s.empty()||s[s.length()-1]!=v[0].first){
        int t = min(2,v[0].second);
        s.insert(s.end(),t,v[0].first);
    }
    return s;
}
int main() {
    int a = 0,b= 0,c = 7;
    string ret = longestDiverseString(a,b,c);
    return 0;
}