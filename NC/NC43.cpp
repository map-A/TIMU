#include "bits/stdc++.h"

using namespace std;

int uniquePaths(int m, int n) {
    long long ret = 1;
    for (int x = n, y = 1; y < m; ++x, ++y) {
        ret = ret * x / y;
    }
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}