#include "bits/stdc++.h"

using namespace std;


void solve(int n,int m){
    int k = pow(10,n-1)/m;
    if(k*m==pow(10,n-1))cout<<k*m;
    else cout<< (k+1)*m;
}
int main() {
    int T;
    cin>>T;
    while (T--){
        int n,m;
        scanf("%d %d",&n,&m);
        solve(n,m);
    }
    return 0;
}