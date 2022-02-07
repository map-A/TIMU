#include "bits/stdc++.h"

using namespace std;
int totalHammingDistance(vector<int> &nums) {
    int ret = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int c = 0;
        for (int val : nums) {
            c += (val >> i) & 1;
        }
        ret += c * (n - c);
    }
    return ret;
}
int main() {

    return 0;
}