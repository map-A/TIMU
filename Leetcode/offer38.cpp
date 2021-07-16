#include "bits/stdc++.h"

using namespace std;

void backtrack(map<char, int> &m, vector<string> &ret, string &tmp, int n) {
    if (tmp.size() == n) {
        ret.push_back(tmp);
    }
    for (auto &i:m) {
        if (i.second > 0) {
            i.second--;
            tmp += i.first;
            backtrack(m, ret, tmp, n);
            i.second++;
            tmp.pop_back();
        }
    }
}

vector<string> permutation(string &S) {
    map<char, int> m;
    for (char & i : S) {
        m[i]++;
    }
    vector<string> ret;
    string tmp;
    backtrack(m, ret, tmp, S.size());
    return ret;
}
vector<string> Permutation(string &s) {
    sort(s.begin(), s.end());
    vector<string>ret;
    ret.push_back(s);
    while(next_permutation(s.begin(), s.end())){
        ret.emplace_back(s);
    };

    return ret;
}
bool nextPermutation_of_own(string& s) {
    int i = s.size() - 2;
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = s.size() - 1;
    while (j >= 0 && s[i] >= s[j]) {
        j--;
    }
    swap(s[i], s[j]);
    reverse(s.begin() + i + 1, s.end());
    return true;
}

int main() {
    string s = "aaabbc";
    vector<string> ret = Permutation(s);
    return 0;
}