#include "bits/stdc++.h"

using namespace std;
int help(int n){
    //找到数字n出了平方根，1，n的因数
    int sq = (int)sqrt(n);
    if(sq*sq==n)return 0;
    int flag=0;
    int ret;
    for (int i = 2; i <= sq; ++i) {
        if(n%i==0){
            ret = n/i;
            flag++;
            if(flag>1) return 0;
        }

    }
    return ret;
}
int sumFourDivisors(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int fac = help(nums[i]);
        if(fac!=0){
            ret+=(nums[i]+1+fac+nums[i]/fac);
        }
    }
    return ret;
}
int main() {

    return 0;
}