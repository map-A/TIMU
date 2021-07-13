#include "bits/stdc++.h"

using namespace std;

int countTriples(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sq = i * i + j * j;
            int t = (int) sqrt(sq);

            if (t <= n && t * t == sq) {
                ret++;
            }
        }
    }
    return ret * 2;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}