#include "bits/stdc++.h"

using namespace std;
bool help(vector<int>&time,int totalTrips,long long t){
    long long ret = 0;
    for (int i = 0; i < time.size(); ++i) {
        ret+=t/ time[i];
        if(totalTrips<=ret) return true;
    }
    return false;

}
long long minimumTime(vector<int>& time, int totalTrips) {
    sort(time.begin(),time.end());
    long long l = 0,r = 1e16;
    long long mid = (r-l)/2+l;
    while (l<r){
        if(help(time,totalTrips,mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
        mid = (r-l)/2+l;
    }
    return l;
}
int main() {
    vector<int>time = {2};
    int totoalTrip = 1;
    auto ret = minimumTime(time,totoalTrip);
    return 0;
}