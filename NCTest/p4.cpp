#include "bits/stdc++.h"

using namespace std;

static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<=b[1];
}

bool xianduan(vector<vector<int>>&lines){
    vector<vector<int>>tmp(lines.begin(),lines.end());
    sort(lines.begin(),lines.end());
    sort(tmp.begin(),tmp.end(),cmp);
    int n = lines.size();
    for(int i=0;i<n;i++){
        if(lines[i][0]==tmp[n-i-1][0]&&lines[i][1]==tmp[n-i-1][1]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}



int main() {
    int n;
    cin>>n;
    vector<vector<int>>lines(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>lines[i][0]>>lines[i][1];
    }
    bool ret = xianduan(lines);
    cout<<ret;
    return 0;
}
