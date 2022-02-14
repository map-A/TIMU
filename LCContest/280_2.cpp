#include "bits/stdc++.h"

using namespace std;

int minimumOperations(vector<int> &nums) {
    if (nums.size() < 2) return 0;
    map<int, int> m1;
    map<int, int> m2;
    for (int i = 0; i < nums.size(); ++i) {
        i % 2 == 0 ? m1[nums[i]]++ : m2[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq2;
    for (auto i: m1) {
        pq1.push({i.second, i.first});
    }

    for (auto i: m2) {
        pq2.push({i.second, i.first});
    }
    if (pq1.top().second != pq2.top().second) {
        return nums.size() - pq1.top().first - pq2.top().first;
    } else {
        auto t1 = pq1.top();
        auto t2 = pq2.top();
        pq1.pop();
        pq2.pop();
        if (pq1.empty() && pq2.empty()) {
            return min(t1.first, t2.first);
        }
        int ret = INT_MAX;
        if (!pq1.empty()) {
            ret = min(ret, (int) nums.size() - pq1.top().first - t2.first);
        }
        if (!pq2.empty()) {
            ret = min(ret, (int) nums.size() - pq2.top().first - t1.first);
        }
        return ret;
    }
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 2};
    int ret = minimumOperations(nums);
    return 0;
}