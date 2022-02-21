#include "bits/stdc++.h"

using namespace std;
bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    if(bits[n-1]==1)return false;
    int index = 0;
    while(index<n){
        if(bits[index]==1){
            index+=2;
            if(index==n)return false;
        }
        else{
            index++;
        }
    }
    return true;
}
int main() {

    return 0;
}