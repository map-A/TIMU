#include "bits/stdc++.h"

using namespace std;
vector<int> solve(int n, int m, vector<int>& a) {
    m=m%n;
    reverse(a.begin(),a.end());
    reverse(a.begin(),a.begin()+m);
    reverse(a.begin()+m,a.end());
    return a;
}
int main() {

    return 0;
}