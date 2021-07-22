#include "bits/stdc++.h"

using namespace std;


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

    sort(intervals.begin(), intervals.end(), cmp);
    if (intervals.size() <= 1) {
        return intervals;
    }
    vector<Interval> ret(intervals.size());
    ret[0].start = intervals[0].start;
    ret[0].end = intervals[0].end;
    int index = 1;
    for (int i = 0; i < intervals.size(); i++) {
        if (ret[index - 1].end >= intervals[i].start) {
            ret[index- 1].start= min(ret[index - 1].start, intervals[i].start);
            ret[index - 1].end = max(ret[index - 1].end, intervals[i].end);
        } else {
            index++;
            ret[index- 1].start = intervals[i].start;
            ret[index - 1].end = intervals[i].end;
        }
    }
    return vector<Interval>(ret.begin(),ret.begin()+index);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}