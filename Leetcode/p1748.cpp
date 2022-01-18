#include "bits/stdc++.h"

using namespace std;
int sumOfUnique(vector<int>& nums) {
    map<int,int>m;
    int ret = 0;
    for(auto i:nums){
        m[i]++;
    }
    for(auto i:m){
        if(i.second==1) ret+=i.first;
    }
    return ret;
}
int main() {

    return 0;
}