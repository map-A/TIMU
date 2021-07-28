#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

#include <bits/stdc++.h>

using namespace std;

/*
 * 每次操作都将某时刻位置置反，请添加一次操作，使得亮的的时间总和最长
 * */
void solve() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n + 2), light(n + 2), dark(n + 2);
    a[0] = 0, a[n + 1] = M;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) {
        light[i] += light[i - 1];
        dark[i] += dark[i - 1];
        if (i & 1) light[i] += a[i] - a[i - 1];
        else dark[i] += a[i] - a[i - 1];
    }

    int ret = light[n + 1]; // 不加入新操作

    for (int i = 0; i <= n; i++) {
        ret = max(ret, light[i] - light[0] + dark[n + 1] - dark[i + 1] + a[i + 1] - a[i] - 1);
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
