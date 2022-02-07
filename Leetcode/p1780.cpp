#include "bits/stdc++.h"

using namespace std;
bool dfs(int n,vector<int>&nums,int index,int sum){


    for (int i = index; i < nums.size(); ++i) {
        sum+=nums[i];
        if(n==sum) return true;
        if(n<sum) return false;
        if(dfs(n,nums,i+1,sum)){
            return true;
        }
        sum-=nums[i];
    }
    return false;
}
bool checkPowersOfThree(int n) {
    vector<int>num(16,0);
    for (int i = 0; i < 15; ++i) {
        num[i] = (int) pow(3,i);
    }
    int sum =0;
    return dfs(n,num,0,sum);
}

int main() {
    int n = 12;
    auto ret = checkPowersOfThree(n);
    return 0;
}