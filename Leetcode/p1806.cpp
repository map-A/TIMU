#include "bits/stdc++.h"

using namespace std;
bool check(vector<int>&perm){
    for(int i=0;i<perm.size();i++){
        if(perm[i]!=i) return false;
    }
    return true;
}
int reinitializePermutation(int n) {
    int ret = 0;
    vector<int>perm(n);
    for(int i=0;i<n;i++) perm[i]=i;
    vector<int>arr(n);
    while(1){
        for(int i=0;i<n;i++){
            i%2==0?arr[i]=perm[i/2]:arr[i]=perm[n/2+(i-1)/2];
        }
        perm = arr;
        ret++;
        if(check(perm)){
            return ret;
        }
    }
    return 0;
}

//洗牌
int reinitializePermutation2(int n) {
    if (n == 2) {
        return 1;
    }
    int k = 1;
    int pow2 = 2;
    while (pow2 != 1) {
        k++;
        pow2 = pow2 * 2 % (n - 1);
    }
    return k;
}
int main() {

    return 0;
}