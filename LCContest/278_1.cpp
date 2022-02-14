#include "bits/stdc++.h"

using namespace std;
int findFinalValue(vector<int>& nums, int original) {
    map<int,int>m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]]++;
    }
    int ret = original;
    while (1){
        if(m.count(ret)){
            ret*=2;
        }
        else{
            return ret;
        }
    }
}
int main() {

    return 0;
}