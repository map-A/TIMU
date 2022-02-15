#include "bits/stdc++.h"

using namespace std;
bool cmp(tuple<string,int,int>&t1,tuple<string,int,int>&t2){
    return get<2>(t1)< get<2>(t2);
}
int main() {
    vector<tuple<string,int,int>>v;
    string s;
    int line;
    while (cin>>s>>line){
        if(v.size()<=8) {
            char *p = strrchr(s.data(), '\\');
            string new_s(p);
            int i=0;
            for (int i = 0; i < v.size(); ++i) {
                if(get<0>(v[i])==new_s&&get<1>(v[i])==line){
                    get<2>(v[i])+=1;
                }
            }
            if(i==v.size()){
                v.push_back({new_s,line,1});
            }
        }
    }
    stable_sort(v.begin(),v.end(), cmp);
    for (int i = 0; i < v.size(); ++i) {
        cout<<get<0>(v[i])<<get<1>(v[i])<<get<2>(v[i])<<endl;
    }
    return 0;
}