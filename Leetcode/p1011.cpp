#include "bits/stdc++.h"

using namespace std;
bool possible(vector<int>&sum,vector<int>&weights,int days,int wgh){

    int ret = 0;
    int t = 0;
    for (int i = 0; i < weights.size(); ++i) {
        if(weights[i]>wgh) return false;
        t+=weights[i];
        if(t>wgh){
            ret++;
            t=weights[i];
        }
    }
    if(t>0)ret++;
    return days>=ret;
}
int shipWithinDays(vector<int>& weights, int days) {
    vector<int>sum(weights.size(),0);
    sum[0]=weights[0];
    for (int i = 1; i < weights.size(); ++i) {
        sum[i]=sum[i-1]+weights[i];
    }
    int l=sum[0],r=sum.back();
    while (l<r){
        int mid = (l+r)/2;
        if(possible(sum,weights,days,mid)){
            r = mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int main() {
   vector<int> weights = {1,2,3,1,1};
   int days = 4;
   int ret = shipWithinDays(weights,days);
    return 0;
}