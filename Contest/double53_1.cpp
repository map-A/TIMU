#include "bits/stdc++.h"

using namespace std;

bool no_repeat(string s) {
    int vis[26];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < s.size(); i++) {
        if (vis[s[i] - 'a'] == 0) {
            vis[s[i] - 'a'] = 1;
        } else return false;
    }
    return true;
}

int countGoodSubstrings(string s) {
    int count = 0;
    if(s.size()<3){
        return count;
    }
    for (int i = 0; i < s.size() - 2; i++) {
        if (no_repeat(s.substr(i, 3))) {
            count++;
        }
    }
    return count;
}

int main() {
    string s = "xyzzaz";
    int ret = countGoodSubstrings(s);
    return 0;
}