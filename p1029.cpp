#include "bits/stdc++.h"

using namespace std;

static bool cmp(vector<int>&a,vector<int>&b){
    return a[0]-b[0]<a[1]-b[1];
}
int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    sort(costs.begin(),costs.end(),cmp);
    int ret = 0;
    for(int i=0;i<n/2;i++){
        ret+=costs[i][0];
        ret+=costs[i+n/2][1];
    }
    return ret;
}
int main() {
   vector<vector<int>>costs ={{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
   int ret = twoCitySchedCost(costs);
    return 0;
}