#include "bits/stdc++.h"

using namespace std;

static bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    if(intervals.size()==0){
        return {newInterval};
    }
    vector<vector<int>> ret;
    intervals.push_back(newInterval);

    sort(intervals.begin(), intervals.end(), cmp);
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

int main() {
    vector<vector<int>> intervals = {{1, 5},
                                     {6, 8}};
    vector<int> newInterval = {0, 9};
    auto ret = insert(intervals, newInterval);
    return 0;
}