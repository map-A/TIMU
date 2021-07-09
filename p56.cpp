
#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> merge1(vector<vector<int>> &intervals) {
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


struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

static bool cmp(Interval &a, Interval &b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
    if(intervals.size()<2) return intervals;
    vector<Interval> ret;
    sort(intervals.begin(), intervals.end(),cmp);
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start <= ret.back().end) {
            ret.back().end = max(ret.back().end, intervals[i].end);
        } else {
            ret.push_back(intervals[i]);
        }
    }
    return ret;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}