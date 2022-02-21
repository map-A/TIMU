#include "bits/stdc++.h"

using namespace std;
vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2 != 0) {
        return {};
    }
    vector<long long> ret;
    long long cnt = 0;
    for (int i = 2; ; i += 2) {
        if (cnt + i > finalSum) {
            ret.back() += finalSum - cnt;
            break;
        }
        ret.push_back(i);
        cnt += i;
    }
    return ret;
}
int main() {

    return 0;
}