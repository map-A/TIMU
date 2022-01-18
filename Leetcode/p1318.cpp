#include "bits/stdc++.h"

using namespace std;
int minFlips(int a, int b, int c) {
    bitset<16>a_bit(a);
    bitset<16>b_bit(b);
    bitset<16>c_bit(c);
    int ret = 0;
    for (int i = 0; i < 16; ++i) {
        if(c_bit[i]==(a_bit[i]|b_bit[i])){
            continue;
        }
        else{
            if(c_bit[i]==1)ret+=1;
            else{
                ret+=(a_bit[i]+b_bit[i]);
            }
        }
    }
    return ret;
}
int main() {
    auto ret = minFlips(2,6,5);
    return 0;
}