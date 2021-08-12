#include "bits/stdc++.h"

using namespace std;



int main() {
    int T=0;
    scanf("%d",&T);
    vector<pair<int,int>>pos(T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&pos[i].first,&pos[i].second);
    }
    int ret = 0;
    for(int x=50;x<=950;x++){
        for(int y=50;y<=950;y++){
            int count = 0;
            for(auto i:pos){
                if(abs(i.first-x)<=50&&abs(i.second-y)<=50){
                    count++;
                }
            }
            ret = max(count,ret);
        }
    }
    cout<<ret;
    return 0;
}