#include "bits/stdc++.h"

using namespace std;
int countPrefixes(vector<string>& words, string s) {
    int ret=0;
    for(auto i:words)ret+=(s.substr(0,i.size())==i);
    return ret;
}
int main() {

    return 0;
}