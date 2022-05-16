#include "bits/stdc++.h"

using namespace std;
double getAdmissionLine(int k, vector<double>& scores) {
    int n = scores.size();
    sort(scores.begin(),scores.end());
    return scores[n-k];
}

int adjustLevel(int cnt) {
    int ret = 0;
    if(cnt==0) return 0;
    for(int i=1;i<=cnt;i++){
        int sq = (int)sqrt(i);
        if(sq*sq==i) ret++;
    }
    return ret;
}


int getKthNum(int k) {
    int n = 0;
    while(1){
        if(((9*n-1)*pow(10,n)+1)/9<k){
            n++;
        }
        else{
            break;
        }
    }
    k-=((9*(n-1)-1)*pow(10,n-1)+1)/9;
    int num = pow(10,n-1)+(k-1)/n;
    int t = k%n;
    string tmp = to_string(num);
    return tmp[(t-1+n)%n]-'0';
}



int main() {

    return 0;
}