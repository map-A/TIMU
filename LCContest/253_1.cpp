#include "bits/stdc++.h"

using namespace std;
bool isPrefixString(string s, vector<string>& words) {
    string t;
    for(auto i:words){
        t+=i;
        if(t==s) return true;
    }
    return false;
}
int main() {

    return 0;
}