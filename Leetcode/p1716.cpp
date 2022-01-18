#include "bits/stdc++.h"

using namespace std;
int totalMoney(int n) {
    vector<int>money = {0,1,3,6,10,15,21,28};
    int total = 0;
    if(n>7){
        total =28*(n/7)+7*(n/7)*(n/7-1)/2;
    }
    total+=(n/7)*(n%7)+money[n%7];
    return total;
}
int main() {
    int n = 10;
    auto ret = totalMoney(n);
    return 0;
}