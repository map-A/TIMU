#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

/*
 * 一共有 n 个箱子排成一排，从左到右依次编号为 1∼n。其中，第 i 号箱子中放有 ai 个石子。
现在，你可以进行最多 d 次操作。
每次操作可以将一个石子从一个箱子移动至另一个与其相邻的箱子里。
我们希望通过合理操作使得 1 号箱子内的石子数量尽可能大。
请问，这个最大可能值是多少？
 * */
void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (d < a[i] * i) {
            ret += d / i;
            break;
        } else {
            ret += a[i];
            d -= a[i] * i;
        }
    }


    cout << ret << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}