#include "bits/stdc++.h"

using namespace std;
vector<int> grayCode(int n) {
    vector<int> ret = {0,1};
    for (int i = 1; i < n; ++i) {
        int len =ret.size();
        for (int j = 0; j <len; ++j) {
            ret.push_back(ret[len-1-j]+len);
        }
    }
    return ret;
}
int main() {

    return 0;
}