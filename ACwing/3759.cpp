#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

void solve() {
    LL n, k;
    cin >> n >> k;
    k--;
    vector<char> v(n, 'a');

    LL first = 0; // 第一个 b 的位置

    for (first = 1; first < n; first++) {
        LL c = (first - 1) * (first) / 2;
        LL d = (first) * (first + 1) / 2;
        if (c <= k && d > k) break;
    }
    LL second = k - (first - 1) * (first) / 2; // 第二个 b 的位置


    v[first] = 'b';
    v[second] = 'b';
    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++) cout << v[i];
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
