#include "bits/stdc++.h"

using namespace std;
int trailingZeroes(int n) {
    int five = 0;
    int temp = n;
    while(temp>0){
        five+=temp/5;
        temp = temp/5;
    }
    int two = 0;
    while(n>0){
        two+=n/2;
        n = n/2;

    }

    return min(five,two);
}
int main() {

    return 0;
}