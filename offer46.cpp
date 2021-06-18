#include "bits/stdc++.h"

using namespace std;
map<string, string> m = {{"ba", "k"},
                         {"bb", "l"},
                         {"bc", "m"},
                         {"bd", "n"},
                         {"be", "o"},
                         {"bf", "p"},
                         {"bg", "q"},
                         {"bh", "r"},
                         {"bi", "s"},
                         {"bj", "t"},
                         {"ca", "u"},
                         {"cb", "v"},
                         {"cc", "w"},
                         {"cd", "x"},
                         {"ce", "y"},
                         {"cf", "z"},
};

void dfs(string &s, set<string> &ss) {

    for (auto i:m) {

        string tmp = s;
        for (int j = 0; j < tmp.size(); j++){
            if (s.find(i.first, j) != string::npos) {
                s.replace(s.find(i.first, j), i.first.size(), i.second);
                ss.insert(s);
                dfs(s, ss);
                s = tmp;
            }
        }
    }
}

int translateNum(int num) {
    string s = to_string(num);
    string tmp;
    for (int i = 0; i < s.size(); ++i) {
        char t = 'a' + s[i] - '0';
        tmp += t;
    }
    set<string> ss;
    ss.insert(tmp);
    dfs(tmp, ss);
    return ss.size();
}

int main() {
    int num = 1212429444;
    cout << translateNum(num);
    return 0;
}