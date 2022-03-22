#include "bits/stdc++.h"

using namespace std;
bool divideArray(vector<int>& nums) {
    vector<int>bz(1002,0);
    for (int i  = 0; i < nums.size(); i ++) bz[nums[i]] ++;
    for (int i  = 0; i < nums.size(); i ++) if (bz[nums[i]] & 1) return false;
    return true;
}
int main() {

    return 0;
}