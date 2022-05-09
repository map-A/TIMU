#include "bits/stdc++.h"

using namespace std;
string largestGoodInteger(string num) {
    vector<string>arr = { "999", "888", "777", "666", "555", "444", "333", "222", "111", "000" };
    for (auto & s : arr) {
        if (num.find(s)!=num.npos) return s;
    }
    return "";
}
int main() {

    return 0;
}