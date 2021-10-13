#include "bits/stdc++.h"

using namespace std;
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    long long sum = accumulate(rolls.begin(),rolls.end(),0);
    int m = rolls.size();
    long long diff = mean*(n+m)-sum;
    int aver = diff/n;
    if(diff>n*6|diff<0||aver==0){
        return {};
    }
    vector<int>ret(n,aver);
    for(int i=0;i<diff-n*aver;i++){
        ret[i]++;
    }
    return ret;
}
int main() {

    return 0;
}