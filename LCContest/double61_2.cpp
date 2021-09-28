#include "bits/stdc++.h"

using namespace std;
vector<int> findOriginalArray(vector<int>& changed) {
    if(changed.size()%2!=0) return {};
    vector<int>vis(100010,0);
    int c[100010];
    //memset 是按照字节赋值，int是4个字节，char是一个字节，并且只能赋值为0，或者1、
    memset(c,0, sizeof(int)*100010);
    for(int i=0;i<changed.size();i++){
        vis[changed[i]]++;
    }
    vector<int>ret;
    for(int i=0;i<vis[0]/2;i++){
        ret.push_back(0);
    }
    for(int i=1;i<vis.size()/2;i++){
        int tmp = vis[i];
        for(int j=0;j<tmp;j++){
            if(vis[i]>0&&vis[2*i]>0){
                vis[i]--;
                vis[2*i]--;
                ret.push_back(i);
            }
            else if(vis[i]>0&&vis[2*i]<=0){
                return {};
            }
            if(ret.size()==changed.size()/2) return ret;
        }
    }
    if(ret.size()==changed.size()/2) return ret;
    return {};
}
int main() {
    vector<int>nums = {0,100000};
    auto ret = findOriginalArray(nums);
    return 0;
}