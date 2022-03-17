#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
int maxInvestment(vector<int>& a, int limits) {
    a.push_back(0);
    sort(a.begin(),a.end(),greater<int>());

    int n=a.size(),ans=0,mod=1e9+7;
    for(int i=0;i+1<n;++i){
        if(a[i]==a[i+1])continue;
        ll x=1ll*(a[i]-a[i+1])*(i+1);
        if(x<=limits){
            ans=(ans+1ll*(a[i+1]+1+a[i])*(a[i]-a[i+1])/2%mod*(i+1)%mod)%mod;
            limits-=x;
        }
        else{
            int lb=a[i]-limits/(i+1),ex=limits%(i+1);
            ans=((ans+(1ll*(lb+1+a[i])*(a[i]-lb)/2)%mod*(i+1)%mod)%mod+1ll*ex*lb%mod)%mod;
            break;
        }
    }
    return ans;
}
int main() {
    vector<int>product = {1,2,3,5,5};
    int limit =10;
    int ret = maxInvestment(product,limit);
    return 0;
}