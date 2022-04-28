#include "bits/stdc++.h"

using namespace std;
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    int t2 = total/cost2;
    long long ret =0;
    for (int i = 0; i <=t2; ++i) {
        ret+=(total-i*cost2)/cost1+1;
    }
    return ret;
}
int main() {

    return 0;
}