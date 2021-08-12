#include "bits/stdc++.h"

using namespace std;

int solve(int* a, int aLen) {
    int a_left = INT_MIN;
    int a_right = INT_MIN;
    for(int i=aLen-1;i>0;i--){
        if(a[i]>=a_right&&a[i]>=a[i-1]) return i;
        a_right = a[i];
    }
    if(a[0]>=a[1]&&a[0]>=a_left) return 0;
    return -1;
}
int main() {

    return 0;
}