#include "bits/stdc++.h"

using namespace std;
bool check(vector<int>&candies,long long k,int mid){
    int i=0;
    while (k>0&&i<candies.size()){
        k-=candies[i]/mid;
        i++;
    }
    return k<=0;
}
int maximumCandies(vector<int>& candies, long long k) {
    std::sort(candies.begin(), candies.end());
    int l = 1;
    long long sum = (long long)std::accumulate(candies.begin(), candies.end(), 0LL);
    long long r = sum/k;
    // cout<<r;
    long long ret = 0;
    if(r<=1||check(candies,k,r)) return r;
    long long  mid =0;
    while (l<r){
        mid = (r-l)/2+l;

        if(check(candies,k,mid)){
            ret = mid;
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return ret;
}
int main() {
    vector<int>candies = {4,7,5};
    int k = 16;
    int ret = maximumCandies(candies,k);
    return 0;
}