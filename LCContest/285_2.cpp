#include "bits/stdc++.h"

using namespace std;
int countCollisions(string directions) {
    int ans = 0, x = 0, y = 0;
    for (char c : directions) {
        if (c == 'L') ans += x;
        else x = 1;
    }

    for (auto c=directions.rbegin();c!=directions.rend();c++) {
        if (*c == 'R') ans += y;
        else y = 1;
    }
    return ans;
}
int main() {

    return 0;
}