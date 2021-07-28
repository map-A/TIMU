#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

const int N = 200010;

int a[N];
int ne[N], c[N];
/*
 * 给定一个 1∼n 的排列 f1,f2,…,fn。已知，对于 1≤i≤n，fi≠i 始终成立。
    现在，因为一些原因，数组中的部分元素丢失了。
    请你将数组丢失的部分补全，要求数组在补全后仍然是一个 1∼n 的排列，并且对于 1≤i≤n， fi≠i 均成立。
 * */

void solve() {
    int n;
    cin >> n;
    vector<int> b;
    set<int> S;
    for (int i = 1; i <= n; i++) S.insert(i);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0)
            b.push_back(i);
        else S.erase(a[i]);
    }

    auto it = S.end();

    for (auto &x : b)
        a[x] = *(--it);

    for (int i = 0; i < b.size(); i++)
        if (a[b[i]] == b[i])
            swap(a[b[i]], a[b[(i + 1) % b.size()]]);

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
