#include "bits/stdc++.h"

using namespace std;
vector<int> maximumBobPoints(int n, vector<int>& a) {
    vector<int> ans(12);
    int x = -1;
    for (int i = 0; i < (1 << 12); ++i) {
        int sum = 0, sumx = 0;
        for (int j = 0; j < 12; ++j) {
            if ((i >> j) & 1) {
                //若i的第j位为1
                sum += a[j] + 1; //剑
                sumx += j;// 得分
            }
        }
        if (sum > n) {
            continue;
        }
        if (sumx > x) {
            x = sumx;
            for (int j = 0; j <12; ++j) {
                if ((i >> j) & 1) {
                    ans[j] = a[j] + 1;
                } else {
                    ans[j] = 0;
                }
            }
            ans[0] += n - sum;
        }
    }
    return ans;
}
int main() {

    return 0;
}