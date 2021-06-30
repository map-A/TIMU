#include "bits/stdc++.h"

using namespace std;

int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    long long hr = llround(hour * 100);
    if (hr <= (n - 1) * 100) {
        return -1;
    }
    int l = 1, r = 1e7;
    while (l < r) {
        int mid = l + (r - l) / 2;
        long long t = 0;
        for (int i = 0; i < n - 1; i++) {
            t += (dist[i] - 1) / mid + 1;//除法向上取整
        }
        t *= mid;
        t += dist[n - 1];
        if (t * 100 <= hr * mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    vector<int> dist = {1,1, 100000};
    double hour = 2.01;
    bool ret = minSpeedOnTime(dist, hour);
    return 0;
}