#include "bits/stdc++.h"

using namespace std;
static bool cmp(vector<int>&a,vector<int>&b){
    if(a[0]<b[0]) return true;
    if(a[0]>b[0]) return false;
    return a[1]>=b[1];

}
int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int ret = 1;
    sort(intervals.begin(),intervals.end(),cmp);
    vector<vector<int>>tmp = {intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
        if(tmp.back()[0]<intervals[i][0]&&intervals[i][0]<=tmp.back()[1]&&intervals[i][1]>tmp.back()[1]){
            tmp.back()[1] = intervals[i][1];
            ret++;
        }
        else if(tmp.back()[0]==intervals[i][0]&&intervals[i][0]<=tmp.back()[1]&&intervals[i][1]>tmp.back()[1]){
            tmp.back()[1] = intervals[i][1];
        }

        else if(intervals[i][1]<tmp.back()[1]){
            continue;
        }
        else if(intervals[i][0]>tmp.back()[1]){
            tmp.push_back(intervals[i]);
            ret++;
        }
    }
    return ret;
}
int main() {
    vector<vector<int>>intervals = {{1,4},{3,6},{2,8},{2,9},{3,7}};
    int ret = removeCoveredIntervals(intervals);
    return 0;
}