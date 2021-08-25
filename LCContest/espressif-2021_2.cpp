#include "bits/stdc++.h"

using namespace std;
int adjustLevel(int cnt) {
    int ret = 0;
    if(cnt==0) return 0;
    for(int i=1;i<=cnt;i++){
        int sq = (int)sqrt(i);
        if(sq*sq==i) ret++;
    }
    return ret;
}
int main() {

    return 0;
}