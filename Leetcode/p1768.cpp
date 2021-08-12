#include "bits/stdc++.h"

using namespace std;

string mergeAlternately(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    int i = 0;
    string ret;
    for (i = 0; i < n && i < m; i++) {
        ret += word1[i];
        ret += word2[i];
    }

    while (i < n) ret += word1[i++];
    while (i < m) ret += word2[i++];
    return ret;
}

int main() {

    return 0;
}