#include "bits/stdc++.h"

using namespace std;
int minBitFlips(int start, int goal) {
    int t = start^goal;
    int ret = 0;
    while (t>0){
        ret+=t&1;
        t = t>>1;
    }
    return ret;
}
int main() {
    int start  =10,goal = 7;
    int ret = minBitFlips(start,goal);
    return 0;
}