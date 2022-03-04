#include "bits/stdc++.h"

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    vector<int> cnt(26);
    for (char c: s){
        cnt[c - 'a'] += 1;
    }
    string t;
    int L = -1;
    while (true) {
        int done = 1;
        int mx = -1;
        for (int i = 25; i >= 0; i -= 1) {
            if (cnt[i] and mx == -1) mx = i;
            if (cnt[i] and i != L) {
                L = i;
                done = 0;
                break;
            }
        }
        if (done) break;
        int x = min(cnt[L], L == mx ? repeatLimit : 1);
        cnt[L] -= x;
        for (int j = 0; j < x; j += 1) t += 'a' + L;
    }
    return t;
}

int main() {

    return 0;
}