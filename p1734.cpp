#include "bits/stdc++.h"

using namespace std;
/*
 * 注意到取偶数位的数进行异或
 * */
vector<int> decode(vector<int> &encoded) {
    int total = 1;
    for (int i = 2; i <= encoded.size() + 1; i++) {
        total = total ^ i;
    }
    int odd = encoded[1];
    for (int i = 3; i < encoded.size(); i += 2) {
        odd = odd ^ encoded[i];
    }
    vector<int> ret(encoded.size() + 1, 0);
    ret[0] = total ^ odd;
    for (int i = 0; i < encoded.size(); i++) {
        ret[i + 1] = ret[i] ^ encoded[i];
    }
    return ret;
}

int main() {
    vector<int> encode = {3, 1};
    vector<int> ret = decode(encode);
    return 0;
}