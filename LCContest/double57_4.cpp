#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ret(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty()) {
            ++ret[i];
            if (heights[i] > heights[s.top()]) {
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(i);
    }
    return ret;
}

int main() {
    return 0;
}
