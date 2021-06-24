#include "bits/stdc++.h"

using namespace std;

int Sum_Solution(int n) {//
    return n * (n + 1) / 2;
}

int sumNums(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret += i;
    return ret;
}

int Sum_Solution(int n) {
    n && (n += Sum_Solution(n - 1));
    return n;
}

int Sum_Solution(int n) {
    if (n = 0) {
        return n;
    } else {
        return n + Sum_Solution(n - 1);
    }
}

int Sum_Solution(int n) {
    int ret = 0;
    int a = n;
    int b = n + 1;
    while (a > 0) {
        (a & 1) && (ret += b);
        a = a >> 1;
        b = b << 1;
    }
    ret = ret >> 1;
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}