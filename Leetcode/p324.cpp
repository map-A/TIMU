#include "bits/stdc++.h"

using namespace std;

void wiggleSort(vector<int> &nums) {
    vector<int> tmp(nums);
    sort(tmp.begin(), tmp.end());
    int n = nums.size();
    for (int i = 1; i < nums.size(); i += 2) {
        nums[i] = tmp[--n];
    }
    for (int i = 0; i < nums.size(); i+=2){
        nums[i] = tmp[--n];
    }
}

int main() {

    return 0;
}