#include "bits/stdc++.h"

using namespace std;

vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
    vector<vector<int>> vp(101);
    for (auto &v: rectangles) {
        //遍历所有矩形
        int l = v[0], h = v[1];
        //l为x，h为y
        for (int j = 0; j <= h; j += 1)
            //右边的线上所有点计入
            vp[j].push_back(l);
    }
    for (int i = 0; i <= 100; i += 1){
        sort(vp[i].begin(), vp[i].end());

    }
    vector<int> res;
    for (auto &v: points) {
        int x = v[0], y = v[1];
        res.push_back(vp[y].size() - (lower_bound(vp[y].begin(), vp[y].end(), x) - vp[y].begin()));
    }
    return res;

}

int main() {

    return 0;
}