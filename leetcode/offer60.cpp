#include "bits/stdc++.h"

using namespace std;
vector<double> dicesProbability(int n) {
    int len = 7;
    vector<double>ret(len,1.0/6);
    for(int k=2;k<=n;k++) {
        vector<double> tmp(len * k);
        for (int i = 1; i < ret.size(); i++) {
            for (int j = 1; j < len; ++j) {
                tmp[i + j] += ret[i] * 1.0 / 6;
            }
        }
        ret = tmp;
    }
    return vector<double>(ret.begin()+n,ret.end()-n+1);
}
int main() {
    int n = 4;
    vector<double>ret = dicesProbability(n);
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i];
    }
    return 0;
}