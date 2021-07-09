#include "bits/stdc++.h"

using namespace std;

int sqrt(int x) {
    int l = 0, r = x;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if ((long long) mid * mid < x) {
            l = mid + 1;
        } else if ((long long) mid * mid > x) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return r;
}

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }
    double x0 = x;
    while (true) {
        double xi = 0.5 * (x0 + x / x0);
        if (fabs(x0 - xi) < 1e-7) {
            break;
        }
        x0 = xi;
    }
    return int(x0);
}


int main() {
    int x = 100;
    int ret = mySqrt(x);
    return 0;
}