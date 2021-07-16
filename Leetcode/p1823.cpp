#include "bits/stdc++.h"

using namespace std;

int findTheWinner(int n, int k) {
    int p = 0;
    for (int i = 2; i <= n; i++) {
        p = (p + k) % i;
    }
    return p + 1;
}

int main() {
    int n= 5,k=2;
    int ret = findTheWinner(n,k);
    return 0;
}