#include "bits/stdc++.h"

using namespace std;
int getKthNum(int k) {
    int n = 0;
    while(1){
        if(((9*n-1)*pow(10,n)+1)/9<k){
            n++;
        }
        else{
            break;
        }
    }
    k-=((9*(n-1)-1)*pow(10,n-1)+1)/9;
    int num = pow(10,n-1)+(k-1)/n;
    int t = k%n;
    string tmp = to_string(num);
    return tmp[(t-1+n)%n]-'0';
}
int main() {
    int k = 10000;
    int ret =  getKthNum(k);
    return 0;
}