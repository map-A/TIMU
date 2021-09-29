#include "bits/stdc++.h"

using namespace std;
int maxIceCream(vector<int>& costs, int coins) {
    int ret = 0;
    sort(costs.begin(),costs.end());
    for(int i=0;i<costs.size();++i){
        if(costs[i]<=coins){
            coins-=costs[i];
            ret++;
        }
        else{
            break;
        }
    }
    return ret;
}
int main() {
    vector<int>costs = {1,3,2,4,1};
    int coins = 7;
    int ret = maxIceCream(costs,coins);
    return 0;
}