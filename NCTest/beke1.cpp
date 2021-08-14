#include "bits/stdc++.h"

using namespace std;

//vector<long> FarmerNN(int n, long long m) {
//    // write code here
//    if (m <= n) {
//        vector<long> ret(n);
//        for (int i = 0; i < m; i++) {
//            ret[i] == 1;
//        }
//        return ret;
//    }
//    vector<long> ret(n, 1);
//    m = m - n;
//    long h = m / (n - 1);
//    long t = m % (n - 1);
//    for (int i = 1; i < n - 1; i++)ret[i] += h;
//    ret[0] += (h + 1) / 2;
//    ret[n - 1] += h / 2;
//    if (h % 2 == 1) {
//        for (int j = 0; j < t; j++) {
//            ret[1 + j]++;
//        }
//    } else {
//        for (int j = 0; j < t; j++) {
//            ret[n - 2 - j]++;
//        }
//    }
//    return ret;
//}


long long section(vector<int> &a, int t) {
    int n = a.size();
    vector<vector<bool>> area(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        int tmp = a[i] ^t;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == tmp) {
                //表示a[i]^a[j]==t
                //以[0,n]为矩形的左上角，[i,j]为矩形的右下角，对area涂色
                for (int l = 0; l <= i; l++) {
                    for (int k = n - 1; k >= j; k--) {
                        area[l][k] = true;
                    }
                }
            }
        }
    }
    //统计上三角中为false的点的个数
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;j++)
            if (area[i][j] == false)ret++;
    }
    return ret;
}

int main() {
    vector<int> a = {2, 4, 8};
    int t = 6;

    auto ret = section(a, t);
    return 0;
}