#include "bits/stdc++.h"

using namespace std;
int minimumSum(int num) {
    vector<int> digits;
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    sort(digits.begin(), digits.end());
    return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
}

int main() {

    return 0;
}