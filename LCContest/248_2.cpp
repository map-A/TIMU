#include "bits/stdc++.h"

using namespace std;
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int ret = 0;
    int n = dist.size();
    vector<double>time(n,0);
    for (int i = 0; i < n; ++i) {
        time[i] = 1.0*dist[i]/speed[i];
    }
    sort(time.begin(),time.end());
    for(int i=0;i<n;++i){
        if(ret>time[i]) return ret;
        ret++;
    }
    return ret;
}
int main() {
    vector<int>dist = {3,2,4};
    vector<int>speed = {5,3,2};
    int ret = eliminateMaximum(dist,speed);
    return 0;
}