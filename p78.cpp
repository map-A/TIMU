#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    vector<int> tmp;
    vector<vector<int>> ret;
    for (int i = 0; i < (1 << n); i++) {
        tmp.clear();
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp.push_back(nums[j]);
            }
        }
        ret.push_back(tmp);
    }
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}