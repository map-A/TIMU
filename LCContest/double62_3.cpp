#include "bits/stdc++.h"

using namespace std;
int maxConsecutiveAnswers(string ans, int k) {
    int n = ans.size();
    int l = 0;
    int r = 0;
    int tNums = 0;
    int fNums = 0;
    while (r < n) {
        if (ans[r] == 'T') {
            tNums++;
        } else {
            fNums++;
        }
        int mx = max(tNums, fNums);
        if (r - l + 1 - mx > k) {
            if (ans[l] == 'T') {
                tNums--;
            } else {
                fNums--;
            }
            ++l;
        }
        ++r;
    }
    return r - l;
}
int main() {

    return 0;
}