#include "bits/stdc++.h"

using namespace std;
int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    vector<int>t(4);
    int k,l,ans=INT_MAX;
    for(int i=1;i<10000;i++)
    {
        t[0]=i/1000;
        t[1]=i/100%10;
        t[2]=i/10%10;
        t[3]=i%10;
        if(t[0]*600+t[1]*60+t[2]*10+t[3]!=targetSeconds)
            continue;
        int j;
        for(j=0;j<4&&!t[j];j++);

        for(l=0,k=startAt;j<4;j++)
        {
            if(k!=t[j])
            {
                k=t[j];
                l+=moveCost;
            }
            l+=pushCost;
        }
        ans=min(ans,l);
    }
    return ans;
}
int main() {

    return 0;
}