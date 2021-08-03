#include "bits/stdc++.h"

using namespace std;

int getLucky(string s, int k) {
    string tmp;
    for (auto i:s) {
        tmp += to_string(i - 'a' + 1);
    }
    int ret = 0;
    for (int i = 0; i < k; i++) {
        ret = 0;
        for (auto i:tmp) {
            ret += i - '0';
        }
        tmp = to_string(ret);
    }
    return ret;
}

int main() {
    string s = "leetcode";
    int ret = getLucky(s, 2);
    return 0;
}