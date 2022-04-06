#include "bits/stdc++.h"

using namespace std;
int slove(vector<int>&nums){
    int ret = 0;
    std::sort(nums.begin(), nums.end(),greater<int>());
    int a,b,c = 0;
    for (int i = 0; i+2 < nums.size(); i+=3) {
        //取前三个
        ret+= nums[i+2];
        a =
    }
}
int main() {

    return 0;
}