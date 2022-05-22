#include "bits/stdc++.h"

using namespace std;
vector<string> removeAnagrams(vector<string>& a) {
    vector<string> b = a;
    for(int i = 0; i < a.size(); ++i) {
        sort(b[i].begin(), b[i].end());
    }
    vector<string> ret;
    for(int i = 0, j = 0; i < a.size(); i = j) {
        while(j < a.size() && b[i] == b[j]) {
            ++j;
        }
        ret.push_back(a[i]);
    }
    return ret;
}


int largestCombination(vector<int>& a) {
    int ret = 0;
    for(int i = 31; i >= 0; --i) {
        int cnt = 0;
        for(int j : a) {
            if(j >> i & 1) {
                ++cnt;
            }
        }
        ret = max(ret, cnt);
    }
    return ret;
}



int main() {

    return 0;
}