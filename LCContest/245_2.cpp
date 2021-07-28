#include "bits/stdc++.h"

using namespace std;

bool isSubSeq(string s, string p) {

    int p_i = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == p[p_i]) {
            p_i++;
        }
    }
    return p_i == p.size();
}

int maximumRemovals(string &s, string p, vector<int> &removable) {
    int ret = 0;
    string tmp = s;
    int l = 0;
    int r = removable.size() - 1;
    while (l <= r) {
        for (int i = 0; i <= (l + r) / 2; ++i) {
            tmp[removable[i]] = ' ';
        }
        if (isSubSeq(tmp, p)) {
            ret = (l + r) / 2 + 1;
            l = (l + r) / 2 + 1;
        } else {
            r = (l + r) / 2 - 1;
            tmp = s;
        }
    }
    return ret;
}

int main() {
    string s = "qlevcvgzfpryiqlwy";
    "[12,5]";
    string p = "qlecfqlw";
    vector<int> a = {12, 5};
    int ret = maximumRemovals(s, p, a);
    return 0;
}