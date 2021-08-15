#include "bits/stdc++.h"

using namespace std;
int mod = 1e9+7;

int minNonZeroProduct(int p)
{
    long long ret = ((1LL << p) - 1) % mod , k = (1LL << p - 1) - 1;
    for(long long multi = ((1LL << p) - 2) % mod ; k ; k >>= 1)
    {
        if(k & 1) ret = ret * multi % mod;
        multi = multi * multi % mod;
    }
    return ret;
}
int main() {

    return 0;
}