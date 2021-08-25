#include "bits/stdc++.h"

using namespace std;
int findGCD(vector<int>& nums) {

    int min_num = *min_element(nums.begin(),nums.end());
    int max_num = *max_element(nums.begin(),nums.end());
    int ret = gcd(min_num,max_num);
    return ret;
}
int main() {

    return 0;
}