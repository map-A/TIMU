#include "bits/stdc++.h"

using namespace std;


bool cmp(map<char, int> &m1, map<char, int> &m2) {
    if (m1.size() != m2.size()) return false;
    for (auto i:m1) {
        if (m2.count(i.first) != 0 && m2.at(i.first) != i.second) {
            return false;
        }
    }
    return true;
}

bool contain(map<char, int> &m1, map<char, int> &m2) {
    for (auto i:m1) {
        if (m2[i.first] < i.second) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    map<char, int> m1;
    map<char, int> m2;
    int l = 0, r = 0;
    for (auto i:s1) {
        m1[i]++;
    }
    while (r < s2.size()) {
        //当m2 覆盖住了所有m1的字符，就可以考虑向右移动l
        while (contain(m1, m2)) {
            if (cmp(m1, m2)) {
                return true;
            }
            m2[s2[l]]--;
            l++;
        }
        m2[s2[r]]++;
        r++;
        //当m2 没有覆盖住了所有m1的字符，就可以考虑向右移动l
    }
    while (contain(m1, m2)) {
        if (cmp(m1, m2)) {
            return true;
        }
        m2[s2[l]]--;
        l++;
    }
    return false;
}

int main() {

    return 0;
}