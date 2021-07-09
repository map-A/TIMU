#include "bits/stdc++.h"

using namespace std;
vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int xorSum = 0;
    for (int num : nums) {
        xorSum ^= num;
    }
    for (int i = 1; i <= n; i++) {
        xorSum ^= i;
    }

    int lowbit = xorSum & (-xorSum);
    int num1 = 0, num2 = 0;
    for (int &num : nums) {
        if ((num & lowbit) == 0) {
            num1 ^= num;
        } else {
            num2 ^= num;
        }
    }
    for (int i = 1; i <= n; i++) {
        if ((i & lowbit) == 0) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }
    }
    for (int num : nums) {
        if (num == num1) {
            return vector<int>{num1, num2};
        }
    }
    return vector<int>{num2, num1};
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}