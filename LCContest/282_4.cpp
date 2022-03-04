#include "bits/stdc++.h"

using namespace std;


int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
    vector<int> minSec(18, INT_MAX / 2);
    for (auto &tire: tires) {
        long time = tire[0];
        for (int x = 1, sum = 0; time <= changeTime + tire[0]; ++x) {
            sum += time;
            minSec[x] = min(minSec[x], sum);
            time *= tire[1];
        }
    }

    vector<int> f(numLaps + 1, INT_MAX);
    f[0] = -changeTime;
    for (int i = 1; i <= numLaps; ++i) {
        for (int j = 1; j <= min(17, i); ++j)
            f[i] = min(f[i], f[i - j] + minSec[j]);
        f[i] += changeTime;
    }
    return f[numLaps];
}


int main() {

    return 0;
}