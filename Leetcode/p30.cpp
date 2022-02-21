#include "bits/stdc++.h"

using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
    map<string,int>m1;
    int len = 0;
    int un = words[0].size();
    for (int i = 0; i < words.size(); ++i) {
        m1[words[i]]++;
        len+=words[i].size();
    }
    vector<int>ret;
    for (int i = 0; i <=(int)s.size()-len; ++i) {
        int start = i;
        map<string,int>m2(m1.begin(),m1.end());
        while (1){
            string sub = s.substr(start,un);
            if(m2.count(sub)&&m2[sub]>0){
                m2[sub]--;
                start+=un;
            }
            else{
                break;
            }
            if(start==i+len){
                ret.push_back(i);
            }
        }
    }
    return ret;
}
int main() {
    string s =  "a";
    vector<string>words  = {"a","a"};
    auto ret = findSubstring(s,words);
    return 0;
}