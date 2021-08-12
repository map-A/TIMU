#include "bits/stdc++.h"

using namespace std;
//背包问题
//price 为价格，买了后的权重，money表示可用的钱数
void solve(vector<int> &price, vector<int> &weight, int money) {
    vector<int> dp(money + 1, 0);
    for (int i = 0; i < weight.size(); ++i) {
        for (int v =money ; v >= price[i]; --v) {
            dp[v] = max(dp[v], dp[v - price[i]] + weight[i]);
        }
    }
   // int ret = *max_element(dp.begin(),dp.end());
    cout << dp[money] << endl;
}

int main() {
    int N, m;
    scanf("%d %d\n", &N, &m);
    vector<int> price(m);
    vector<int> weight(m);
    vector<int> q(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &price[i], &weight[i], &q[i]);
    }
    vector<int> new_price;
    vector<int> new_weight;
    //vector<int>new_q;
    map<int, int> ma;//int->出现的主件，主件加附件在new_weight里下标
    for (int i = 0; i < m; i++) {
        if (q[i] == 0) {
            new_price.push_back(price[i]);
            new_weight.push_back(weight[i] * price[i]);
        } else {
            new_price.push_back(price[i] + price[q[i] - 1]);
            new_weight.push_back(weight[q[i] - 1] * price[q[i] - 1] + price[i] * weight[i]);
            if (ma.count(q[i]) == 0) {
                ma[q[i]] = new_price.size();
            } else {
                new_price.push_back(price[i] + new_price[ma[q[i]] - 1]);
                new_weight.push_back(weight[i] * price[i] + new_weight[ma[q[i]] - 1]);
            }
        }
    }


    solve(new_price, new_weight, N);

    return 0;
}