#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end());
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= ret.back()[1]) {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        } else {
            ret.push_back(intervals[i]);
        }
    }
    return ret;
}
vector<vector<int>>interval(vector<vector<int>>&intervals){
    vector<vector<int>>ret;
    sort(intervals.begin(), intervals.end());
    auto prev = intervals[0];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=prev[1]){
            vector<int>tmp = {intervals[i][0],min(prev[1],intervals[i][1])};
            prev[0] = min(prev[1],intervals[i][1]);
            prev[1] = max(prev[1],intervals[i][1]);
            ret.push_back(tmp);
        }
        else{
            prev=intervals[i];
        }
    }
    return ret;
}
void solve(vector<vector<int>>&intervals){
    auto m = merge(intervals);
    auto it = interval(intervals);
    int ret = 0;
    for(int i=0;i<m.size();i++){
        ret+=(m[i][1]-m[i][0]);
    }
    for(int i=0;i<it.size();i++){
        ret-=(it[i][1]-it[i][0]);
    }
    cout<<ret;
}
int main() {
    int n;
    scanf("%d\n",&n);
    vector<vector<int>>intervals(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        scanf("%d,%d",&intervals[i][0],&intervals[i][1]);
    }
    solve(intervals);
    return 0;
}