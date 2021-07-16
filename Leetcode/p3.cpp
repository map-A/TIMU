//
// Created by mm on 2021/6/15 0015.
//

#include "bits/stdc++.h"
using namespace std;

int lengthOfLongestSubstring(string s) {
    //TODO: give an another efficient algorithm
    unordered_set<char>us;
    int n = s.length();
    int r = -1, ret = 0;
    for (int i = 0; i < n; ++i) {
        if (i != 0) us.erase(s[i - 1]);
        while (r + 1 < n && !us.count(s[r + 1])) {
            us.insert(s[r + 1]);
            ++r;
        }
        ret = max(ret, r - i + 1);
    }
    return ret;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}