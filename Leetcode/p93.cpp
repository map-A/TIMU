#include "bits/stdc++.h"

using namespace std;
bool help(string s){
    int t = stoi(s);
    if(t<256&& to_string(t)==s) return true;
    return false;
}
vector<string> restoreIpAddresses(string s) {
    if(s.size()<4||s.size()>12)return {};
    vector<string>ret;
    for (int i = 1; i <= 3; ++i) {
        string t = s.substr(0,i);
        if(help(t)&&i<s.size()){
            t+=".";
            for (int j = i+1; j-i <= 3; ++j) {
                string tt = s.substr(i,j-i);
                if(help(tt)&&j<s.size()){
                    tt+=".";
                    for (int k = j+1; k-j <= 3; ++k) {
                        string ttt = s.substr(j,k-j);
                        if(help(ttt)&&k<s.size()){
                            ttt+=".";
                            string tttt = s.substr(k);
                            if(help(tttt)){
                                ret.push_back(t+tt+ttt+tttt);
                            }
                        }
                    }
                }

            }
        }
    }
    return ret;
}
int main() {
    string s = "1111";
    auto ret = restoreIpAddresses(s);
    return 0;
}