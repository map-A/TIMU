#include "bits/stdc++.h"

using namespace std;
vector<string> cellsInRange(string s) {
    vector<string> v;
    for(char i=s[0];i<=s[3];i++)
        for(char j=s[1];j<=s[4];j++){
            string t;
            t += i;
            t += j;
            v.emplace_back(t);
        }
    return v;
}
int main() {

    return 0;
}