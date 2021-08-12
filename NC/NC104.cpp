#include "bits/stdc++.h"

using namespace std;


string removeZero(const string &s){
    bool flag = true;
    int index = 0;
    for(auto i:s){
        if(i=='0'&&flag){
            index++;
        }
        else{
            break;
        }
    }
    string ret = s.substr(index);
    return ret.empty()?"0":ret;
}

bool compareStr(const string &s1,const string s2){
    if(s1.size()>s2.size()) return true;
    return s1>s2;
}

int compare(string version1, string version2) {

    stringstream v1(version1);
    stringstream v2(version2);
    string temp;
    vector<string>vec1;
    while(getline(v1, temp, '.')){
        string tt = removeZero(temp);
        vec1.push_back(tt);
    };
    vector<string>vec2;
    while(getline(v2,temp,'.')){
        string tt = removeZero(temp);
        vec2.push_back(tt);
    }
    int p1 = 0,p2 = 0;
    while(p1<vec1.size()&&p2<vec2.size()){
        if(compareStr(vec1[p1],vec2[p2])) return 1;
        else if(compareStr(vec2[p2],vec1[p1])) return -1;
        p1++;
        p2++;
    }
    while(p1<vec1.size()){
        if(vec1[p1]!="0") return 1;
        p1++;
    }
    while(p2<vec2.size()){
        if(vec2[p2]!="0") return -1;
        p2++;
    }
    return 0;
}
int main() {
    string v1 = "1.001.1";
    string v2 = "1.01.1";
    int ret = compare(v1,v2);
    return 0;
}