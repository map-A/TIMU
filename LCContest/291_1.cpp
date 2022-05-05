#include "bits/stdc++.h"

using namespace std;
string removeDigit(string number, char digit) {
    string ans, best;
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] == digit) {
            best = number.substr(0, i) + number.substr(i + 1);
            if (i < number.size() - 1 and number[i + 1] > digit)
                return best;
            else
                ans = best;
        }
    }
    return ans;
}
int main() {

    return 0;
}