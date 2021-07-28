#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;


/*
 * 在一个数组中，选择一些数组成新的序列，并排好序。
 * 这个序列要么满足 相邻的下标之差等于值之差。下标置这些元素在原有数组中的下标，并且序列的总和最大
 *
 * */
void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    map<int, LL> mp;

    LL ret = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i] - i] += a[i];
    }

    for (int i = -200010; i <= 400010; i++) {
        ret = max(ret, mp[i]);
    }
    cout << ret << endl;
}

int main() {
    solve();
    return 0;
}
