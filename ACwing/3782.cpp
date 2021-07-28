#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
 * 给定一个平面上的 N 个点，请你计算所有点对之间距离的平方和
 * */

ll point_distance_sum(vector<ll>&x,vector<ll>&y){
    int n = x.size();
    ll ret = 0, sumx = 0, sumy = 0;
    for(int i = 0; i < n; i++) {
        sumx += x[i];
        sumy += y[i];
    }
    for(int i = 0; i < n; i++) {
        ret += n * (x[i] * x[i] + y[i] * y[i]);
        ret -= x[i] * sumx + y[i] * sumy;
    }
    return ret;
}


int main() {

    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll ret = point_distance_sum(x,y);
    cout << ret << endl;
    return 0;
}
