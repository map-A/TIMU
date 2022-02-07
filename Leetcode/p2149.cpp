#include "bits/stdc++.h"

using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;
    vector<int> ret(n);
    for (int num : nums) {
        if (num > 0) {
            ret[i] = num;
            i += 2;
        } else {
            ret[j] = num;
            j += 2;
        }
    }
    return ret;
}
int main() {

    return 0;
}