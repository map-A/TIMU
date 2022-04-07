#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    vector<pair<int,int>>t(1e5+1,{0,0});
    for (int i = 0; i < matches.size(); ++i) {
        t[matches[i][0]]= make_pair(t[matches[i][0]].first+1,t[matches[i][0]].second);
        t[matches[i][1]]= make_pair(t[matches[i][1]].first,t[matches[i][1]].second+1);
    }
    vector<int>ans1;
    vector<int>ans2;
    for (int i = 1; i < t.size(); ++i) {
        if(t[i].first>0&&t[i].second==0){
            //全胜
            ans1.push_back(i);
        }
        else if(t[i].second==1){
            ans2.push_back(i);
        }
    }
    return {ans1,ans2};
}
int main() {

    return 0;
}