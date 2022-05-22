#include "bits/stdc++.h"

using namespace std;
using pll = pair<long long, long long>;

//def percentageLetter(self, s: str, letter: str) -> int:
//    return floor(s.count(letter) / len(s) * 100)

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n=capacity.size();
    vector<int> ew(n);
    for(int i=0;i<n;i++){
        ew[i]=capacity[i]-rocks[i];
    }
    sort(ew.begin(),ew.begin()+n);
    int i=0;
    int ans=0;
    while(i<n&&additionalRocks>=0){
        if(ew[i]==0){
            ans++;
        }
        else if(additionalRocks>=ew[i]){
            ans++;
        }
        additionalRocks-=ew[i];
        i++;
    }
    return  ans;
}

int minimumLines(vector<vector<int>>& s) {
    int n = s.size();
    if(n == 1) return 0;
    sort(s.begin(), s.end());
    pll k = {s[1][1]-s[0][1], s[1][0]-s[0][0]};
    int ans = 1;
    for(int i = 2; i < n; ++i) {
        pll t = {s[i][1]-s[i-1][1], s[i][0]-s[i-1][0]};
        if(k.first*t.second != t.first*k.second) {
            k = t;
            ++ans;
        }
    }
    return ans;
}

int main() {

    return 0;
}