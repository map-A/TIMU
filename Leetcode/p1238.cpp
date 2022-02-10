#include "bits/stdc++.h"

using namespace std;
vector<int> circularPermutation(int n, int start) {
    int nn = 1<<n;
    vector<int> res(nn, 0);
    for (int i = 0; i < nn; ++i)
    {
        res[i] = i ^ (i>>1) ^ start;
    }

    return res;
}
int main() {

    return 0;
}