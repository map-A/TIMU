#include "bits/stdc++.h"

using namespace std;
int minMoves(vector<int>& nums) {
    return accumulate(begin(nums), end(nums), 0) - size(nums) * *min_element(begin(nums), end(nums));
}
int main() {

    return 0;
}