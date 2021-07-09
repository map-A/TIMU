#include "bits/stdc++.h"

using namespace std;

long long fast(long long a, long b, long p) {
    long long a1 = a, t = 1;

    while (b > 0) {
        if (b & 1)
            t = (t % p) * (a1 % p) % p;
        a1 = (a1 % p) * (a1 % p) % p;

        b /= 2;
    }

    return (long long) (t % p);

}

int countGoodNumbers(long long n) {
    int ret;
    long long mod = 1e9 + 7;
    if (n % 2 == 0) {
        ret = (fast(4, n / 2, mod) * fast(5, n / 2, mod)) % mod;
    } else {
        ret = (fast(4, n / 2, mod) * fast(5, n / 2 + 1, mod)) % mod;
    }
    return ret;
}

int main() {
    int n = 806166225460392;
    int ret = countGoodNumbers(n);
    return 0;
}