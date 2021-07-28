#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

/*
 * 给一个数组arr,出发点x,终点y，从x到y要走一定的步数，每一步的距离只能在arr里选，那么最少要走多少步。
 * x，y均为二维坐标
 * */
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    sort(a.begin(), a.end());

    int ret = 0;

    if (x < a[n - 1]) {
        if (mp[x]) ret = 1;
        else ret = 2;
    } else {
        ret = (x + a[n - 1] - 1) / a[n - 1];
    }

    cout << ret << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

