#include "bits/stdc++.h"

using namespace std;

int add(int num1, int num2) {
    int tmp = 0;
    while (num2 != 0) {
        tmp = (num1 & num2) << 1;
        num1 ^= num2;
        num2 = tmp;
    }
    return num1;
}

int Add(int num1, int num2) {
    vector<int> v = {num1, num2};
    return accumulate(v.begin(), v.end(), 0);
}

int main() {
    int a = 3;
    int b = 7;
    int ret = add2(a, b);
    return 0;
}