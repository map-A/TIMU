#include "bits/stdc++.h"

using namespace std;

int minSwaps(string s) {
    int n = s.size();

    int ret = 0;
    int balance = 0;
    int right = n - 1;
    for (int i = 0; i < right; i++) {
        if (s[i] == '[') {
            balance += 1;
        } else {
            balance -= 1;
        }
        if (balance < 0) {
            //从最右边找一个左括号
            for (; right > i; right--) {
                if (s[right] == '[') {
                    ret += 1;
                    swap(s[i], s[right]);
                    balance = 0;
                    i -= 1;
                    break;
                }
            }
        }
    }
    return ret;
}

int main() {

    return 0;
}