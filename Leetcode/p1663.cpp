#include "bits/stdc++.h"

using namespace std;
string getSmallestString(int n, int k) {
    string ret(n,'a');
    k = k-n;
    int index=0;
    while (k>0){
        if(k>25){
            ret[index]='z';
            index++;
            k-=25;
        }
        else{
            ret[index] = 'a'+k;
            k=0;
        }
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main() {
    int n=5,k=73;
    auto ret = getSmallestString(n,k);
    return 0;
}