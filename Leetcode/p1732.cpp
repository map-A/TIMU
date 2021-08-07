#include "bits/stdc++.h"

using namespace std;
int largestAltitude(vector<int>& gain) {
    int altitude = 0;
    int ret = 0;
    for(int i=0;i<gain.size();i++){
        altitude +=gain[i];
        ret = max(ret,altitude);
    }
    return ret;
}
int main() {

    return 0;
}