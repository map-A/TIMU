#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    vector<int>ret,origin;
    Solution(vector<int>& nums) {
        origin = nums;
        ret = nums;
    }

    vector<int> reset() {
        return origin;
    }

    vector<int> shuffle() {

        for (int i = 1; i < ret.size(); ++i)
        {
            int r = rand() % (i + 1);
            if (r != i)
            {
                swap(ret[r], ret[i]);
            }
        }
        return ret;
    }
};

int main() {

    return 0;
}