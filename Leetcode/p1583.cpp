#include "bits/stdc++.h"

using namespace std;
bool help(vector<vector<int>>&preference,vector<int>&a,vector<int>&b
        ){
    //x与y和u的亲近程度
    int n = preference.size();
    int xy=n,xu=n;
    for (int i = 0; i < preference[a[0]].size(); ++i) {
        if(preference[a[0]][i]==a[1]){
            xy = i;
        }
        else if(preference[a[0]][i]==b[0]){
            xu = i;
        }
    }
    //ux 和uy
    int ux=n,uv=n;
    for (int i = 0; i < preference[b[0]].size(); ++i) {
        if(preference[b[0]][i]==b[1]){
            uv = i;
        }
        else if(preference[b[0]][i]==a[0]){
            ux=i;
        }
    }
    return xy>xu&&ux<uv;
}
int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
    vector<int>ret(n,0);
    int ans = 0;
    for (int i = 0; i < pairs.size(); ++i) {
        for (int j = i+1; j < pairs.size(); ++j) {
            auto tmpxy = pairs[i];
            swap(tmpxy[0], tmpxy[1]);
            auto tmpuv = pairs[j];
            swap(tmpuv[0], tmpuv[1]);
            if(ret[pairs[i][0]]==0&&(help(preferences,pairs[i],pairs[j])|| help(preferences,pairs[i],tmpuv))){
                ret[pairs[i][0]]=1;
                ans++;
            }
            if(ret[tmpxy[0]]==0&&(help(preferences,tmpxy,pairs[j])|| help(preferences,tmpxy,tmpuv))){
                ret[tmpxy[0]] = 1;
                ans++;
            }
            if(ret[pairs[j][0]]==0&&(help(preferences,pairs[j],pairs[i])|| help(preferences,pairs[j],tmpxy))){
                ret[pairs[j][0]]=1;
                ans++;
            }
            if(ret[tmpuv[0]]==0&&(help(preferences,tmpuv,pairs[i])|| help(preferences,tmpuv,tmpxy))){
                ret[tmpuv[0]] = 1;
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    int n = 4;
    vector<vector<int>> preferences = {
            {1,3,2,},
            {2,3,0},
            {1,3, 0},
            {0,2, 1}};
    vector<vector<int>> pairs = {{1,3},
                                 {0,2}};
    int ret = unhappyFriends(n, preferences, pairs);

    return 0;
}