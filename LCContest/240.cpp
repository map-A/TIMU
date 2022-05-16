#include "bits/stdc++.h"

using namespace std;
int maximumPopulation(vector<vector<int>>& logs) {
    int age[101] = {0};
    for(int i=0;i<logs.size();i++){
        for(int j = logs[i][0];j<logs[i][1];j++){
            age[j-1950]++;
        }
    }
    int ret  = 0;
    int year = 0;
    for(int i=0;i<101;i++){
        if(ret<age[i]){
            year = 1950+i;
            ret = age[i];
        }
    }
    return year;
}


int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int ret = 0;
    for (int j = 0; j < n2; ++j){
        while (i < n1 && nums1[i] > nums2[j]){
            ++i;
        }
        if (i < n1){
            ret = max(ret, j - i);
        }
    }
    return ret;
}

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
void solve2(vector<int>&v,vector<int>&w,const int pow){
    vector<int>dp(pow+1,0);
    for(int i=0;i<v.size();i++){
        for(int j=pow;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[pow];

}

void solve3(vector<int>&vec){
    if(vec.empty()) return;
    vector<int>odd;
    vector<int>even;
    for(int i=0;i<vec.size();i++){
        if(vec[i]%2==0)even.push_back(vec[i]);
        else odd.push_back(vec[i]);
    }
    for(auto i:even){
        cout<<i<<',';
    }
    for(int i=0;i<odd.size()-1;i++){
        cout<<odd[i]<<',';

    }
    cout<<odd.back();
}
int main() {

    return 0;
}