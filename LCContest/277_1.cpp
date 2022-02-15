#include "bits/stdc++.h"

using namespace std;
int countElements(vector<int>& nums) {
    int smallest = *min_element(nums.begin(), nums.end());
    int largest = *max_element(nums.begin(), nums.end());
    int res = 0;
    for (int num: nums) {
        if (smallest < num && num < largest) {
            ++res;
        }
    }
    return res;
}
int main() {

    return 0;
}