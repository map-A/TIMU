#include "bits/stdc++.h"

using namespace std;
double getAdmissionLine(int k, vector<double>& scores) {
    int n = scores.size();
    sort(scores.begin(),scores.end());
    return scores[n-k];
}
int main() {

    return 0;
}