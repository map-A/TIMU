#include "bits/stdc++.h"

using namespace std;

int solve(string s1,string s2){
    int ret = 0;
    for (int i = 0; i < s1.size()-s2.size()+1; ++i) {
        for (int j = s2.size(); j < s1.size()-i+1; ++j) {
            string s = s1.substr(i,j);
            if(s.find(s2)!=s.npos){
                ret+=s1.size()-i-j+1;
                break;
            }
        }

    }
    return ret;
}


int main() {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ret = solve(s1,s2);
    return 0;
}