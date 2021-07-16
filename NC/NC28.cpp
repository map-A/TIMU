#include "bits/stdc++.h"

using namespace std;


bool check(string T, string S) {
    //检查S是否为t的子串
    map<char, int> m;
    for (int i = 0; i < S.size(); i++) {
        m[S[i]]++;
    }
    for (int i = 0; i < T.size(); i++) {
        if (m[T[i]] > 0)m[T[i]]--;
        else {
            return false;
        }
    }
    return true;
}

string minWindow(string S, string T) {
    int left = 0, right = 0, start = 0, minLen = INT_MAX;
    unordered_map<char, int> need;
    unordered_map<char, int> window;
    for (auto i:T)need[i]++;

    int match = 0;
    while (right < S.length()) {
        char c1 = S[right];
        if (need.count(c1)) {
            window[c1]++;
            if (window[c1] == need[c1])match++;
        }
        right++;
        while (match == need.size()) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }
            char c2 = S[left];
            if (need.count(c2)) {
                window[c2]--;
                if (window[c2] < need[c2]) match--;
            }
            left++;
        }
    }
    return minLen == INT_MAX ? "" : S.substr(start, minLen);
}


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ret = minWindow(s, t);
    return 0;
}