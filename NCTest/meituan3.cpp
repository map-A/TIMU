#include "bits/stdc++.h"

using namespace std;
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

long long n,a[1000005],f[1000005],g[1000005],b[1000005],ans=1e18,s=0;
int main()
{
    scanf("%d",&n);
    rep(i,1,n){scanf("%d",&a[i]);b[i]=a[i];}
    rep(i,1,n)
        if(a[i]<=a[i-1]){f[i]=f[i-1]+a[i-1]+1-a[i];a[i]=a[i-1]+1;}else f[i]=f[i-1];
    dep(i,n,1)
        if(b[i]<=b[i+1]){g[i]=g[i+1]+b[i+1]+1-b[i];b[i]=b[i+1]+1;}else g[i]=g[i+1];
    rep(k,0,n){
        s=f[k]+g[k+1];
        if(a[k]==b[k+1])s++;
        if(s<ans)ans=s;
    }
    cout<<ans<<endl;
    return 0;
}