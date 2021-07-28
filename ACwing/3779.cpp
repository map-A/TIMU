#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

const int N = 200010;

/*
 * 题意就是找删去一个元素后和相同的组和删除的元素
 * 在两个序列中，哥删除一个元素，使得他们的序列和相等，返回删除的元素
 * */



struct Node {
    int who, num;
} table[N];


void input(int &k, vector<vector<int>>&all, vector<int> &sum) {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int a;
        scanf("%d", &a);
        for (int j = 1, v; j <= a; j++)
            scanf("%d", &v), all[i].push_back(v), sum[i] += v;
    }
}

void solve(int k, vector<vector<int>>&all, vector<int> &sum) {
    unordered_map<int, int> H;
    int idx = 0;
    for (int i = 1; i <= k; i++) {

        for (int j = 0; j < all[i].size(); j++) {
            int diff = sum[i] - all[i][j];
            if (H.count(diff + 200010)) {
                auto &t = table[H[diff + 200010]];
                if (t.who == i) continue;
                puts("YES");
                printf("%d %d\n", i, j + 1);
                printf("%d %d\n", t.who, t.num + 1);
                return;
            } else H[diff + 200010] = idx, table[idx] = {i, j}, idx++;

        }
    }
    puts("NO");
}


int main() {
    vector<vector<int>>all(N);
    vector<int>sum(N);
    int k = 0;
    input(k,all,sum);
    solve(k,all,sum);
    return 0;
}
