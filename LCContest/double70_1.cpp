#include "bits/stdc++.h"

using namespace std;
int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end(),greater<int>());
    int ret = accumulate(cost.begin(),cost.end(),0);
    for (int i = 2; i < cost.size(); i+=3) {
        ret-=cost[i];
    }
    return ret;
}
int main() {

    vector<int>cost = {1,2,3};
    int ret = minimumCost(cost);
    return 0;
}