#include "bits/stdc++.h"

using namespace std;

string simplifyPath(string path) {
    stack<char> s;
    s.push('/');
    for (int i = 1; i < path.size(); i++) {
        if (s.empty()) {
            s.push('/');
        }
        if (path[i] == '/' && s.top() == '/') {
            continue;
        } else if (path[i] == '/' && s.top() != path[i]) {
            s.push(path[i]);
        } else if (path[i] == '.') {
            if (s.top() == '/') {
                if (path.substr(i, 2) == "./") {
                    i++;
                    continue;
                } else if (path.substr(i, 2) == "..") {
                    if (i + 2 < path.size() && path[i + 2] == '/' || i + 2 > path.size() - 1) {
                        s.pop();
                        while (!s.empty() && s.top() != '/') {
                            s.pop();

                        }
                        i += 1;
                    } else {
                        for (int j = i; j <= i + 2; j++) {
                            s.push(path[j]);
                        }
                        i = i + 2;
                    }
                } else if (i + 1 < path.size() - 1 && path[i + 1] != '/') {
                    s.push(path[i]);
                }
            }
            else{
                s.push(path[i]);
            }
        } else {
            s.push(path[i]);
        }
    }

    if (s.size() < 2) return "/";
    string ret;
    while (!s.empty()) {
        ret = s.top() + ret;
        s.pop();
    }
    if (ret[ret.size() - 1] != '/') return ret;
    return ret.substr(0, ret.size() - 1);
}

int main() {
    string path = "/home/foo/.ssh/../.ssh2/authorized_keys/";
    auto ret = simplifyPath(path);
    return 0;
}