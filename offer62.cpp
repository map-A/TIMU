#include "bits/stdc++.h"

using namespace std;

int lastRemaining(int n, int m) {
    vector<int> l;
    for (int i = 0; i < n; i++) {
        l.push_back(i);
    }
    int tmp = 0;
    while (l.size() > 1) {
        tmp = (tmp + m - 1 + l.size()) % l.size();
        auto i = l.begin() + tmp;
        l.erase(l.begin() + tmp);
    }
    return *l.begin();
}

int LastRemaining_Solution(int n, int m) {
    if (n <= 0) {
        return -1;
    }
    int p = 0;
    for (int i = 2; i <= n; i++) {
        p = (p + m) % i;
    }
    return p;
}

int main() {
    int n = 5;
    int m = 3;
    int ret = lastRemaining(n, m);
    return 0;
}