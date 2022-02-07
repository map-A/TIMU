#include "bits/stdc++.h"

using namespace std;
bool help(vector<int>&bloomDay,int day,int k,int m){
    vector<int>ret = {0};
    int t = 0;
    for (int i = 0; i < bloomDay.size(); ++i) {
        if(bloomDay[i]<=day)ret.back()++;
        else{
            ret.push_back(0);
            t = 0;
        }
    }
    int numdays = 0;
    for (int i = 0; i < ret.size(); ++i) {
        numdays+=ret[i]/k;
    }
    return numdays>=m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    if(m*k>bloomDay.size()) return -1;
    vector<int>sortedDays(bloomDay);
    sort(sortedDays.begin(),sortedDays.end());
    int l=m*k-1,r = sortedDays.size()-1;
    while (l<r){
        int mid = (r-l)/2+l;
        if(help(bloomDay,sortedDays[mid],k,m)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return sortedDays[l];
}
int main() {
    vector<int>bloomDays = {1,10,3,10,2};
    int m= 3,k=1;
    int ret = minDays(bloomDays,m,k);
    return 0;
}