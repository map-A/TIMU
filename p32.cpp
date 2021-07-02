#include "bits/stdc++.h"

using namespace std;
static bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] <= b[0];
}
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ret;
    if(intervals.empty()) return ret;

    sort(intervals.begin(), intervals.end(), cmp);
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= ret.back()[1]+1) {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        }
        else {
            ret.push_back(intervals[i]);
        }
    }
    return ret;
}

int longestValidParentheses(string s) {
    vector<vector<int>>interval;
    stack<int>index;
    for(int i=0;i<s.size();i++){
        if(index.empty()||s[i]=='('){
            index.push(i);
            continue;
        }
        if (s[i]==')'&&s[index.top()]=='('){
            interval.push_back({index.top(),i});
            index.pop();
        }
        else{
            index.push(i);
        }
    }
    vector<vector<int>>ret = merge(interval);
    int tmp = INT_MIN;
    for(int i=0;i<ret.size();i++){
        tmp = max(tmp,ret[i][1]-ret[i][0]);
    }
    return tmp==INT_MIN?0:tmp;
}


int main() {
    string s = "";
    int ret = longestValidParentheses(s);
    return 0;
}