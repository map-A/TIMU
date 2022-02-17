#include "bits/stdc++.h"

using namespace std;
int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long l = lower,r  = upper;
    long long t = 0;
    for (int i = 0; i < differences.size(); ++i) {
        t+=differences[i];
        l = max(l,lower+t);
        r = min(r,upper+t);
    }
    return r-l+1>0?r-l+1:0;
}
int main() {
    vector<int>dirfference = {1,-3,4};
    int lower = 1,upper = 6;
    int ret  = numberOfArrays(dirfference,lower,upper);
    return 0;
}