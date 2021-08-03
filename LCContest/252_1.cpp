#include "bits/stdc++.h"

using namespace std;

bool isThree(int n) {
    if(n<3) return  false;
    int sq = (int)sqrt(n);
    if(n==sq*sq){
        for(int i=2;i<sq;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    string s = "leetcode";

    return 0;
}