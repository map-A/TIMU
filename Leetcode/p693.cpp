#include "bits/stdc++.h"

using namespace std;
bool hasAlternatingBits(int n) {
    int tmp= n&1;
    n = n>>1;
    while(n>0){
        int a = n&1;
        if(a==tmp) return false;
        tmp = a;
        n = n>>1;
    }
    return true;
}
int main() {

    return 0;
}