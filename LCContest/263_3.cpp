#include "bits/stdc++.h"

using namespace std;

int countMaxOrSubsets(vector<int> &nums) {

    int ret = 0, maxVal = 0, n = (int) nums.size();
    for (int i = 1; i < (1 << n); ++i) { //从1-2^n
        int max_num = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) max_num |= nums[j];

            if (maxVal < max_num) {
                ret = 1;
                maxVal = max_num;
            } else if (maxVal == max_num) ++ret;
        }
        return ret;
    }
}