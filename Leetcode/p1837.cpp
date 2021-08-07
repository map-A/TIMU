#include "bits/stdc++.h"

using namespace std;
int sumBase(int n, int k) {
    int ans = 0 ;
    while(n){
        ans += n % k;
        n /= k;
    }
    return ans;
}
int main() {
    int n = 34,k = 6;
    int ret = sumBase(n,k);
    return 0;
}