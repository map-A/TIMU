#include "bits/stdc++.h"

using namespace std;
int solve(int m,vector<int>&pos){
    int ret = pos[0]*m;//在第一站买完;
    int index = 0;
    for (int i = 1; i < pos.size(); ++i) {
        if(pos[i]>pos[index]){
            continue;
        }
        else{
            ret-=(m-i)*pos[index];//把到达这站多余的食物去掉
            ret+=(pos[i])*(m-i);
            index = i;
        }
    }
    return ret;
}
int main() {
    int m,n;
    cin>>m>>n;
    vector<int>pos(n,0);
    int t,tt;
    for (int i = 0; i < n; ++i) {
        cin>>t>>tt;
        pos[t] = tt;
    }

    auto ret = solve(m,pos);
    return 0;
}