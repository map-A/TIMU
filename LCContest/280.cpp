#include "bits/stdc++.h"

using namespace std;
int countOperations(int num1, int num2) {
    int ret = 0;
    while (num1!=0&&num2!=0){
        if(num1>num2){
            num1-=num2;
        }
        else{
            num2-=num1;
        }
        ret++;
    }
    return ret;

}

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

long long minimumRemoval(vector<int>& beans) {

    sort(beans.begin(),beans.end());
    vector<int>tmp;
    for (int i = 0; i < beans.size(); ++i) {
        if(beans[i]!=0){
            tmp.push_back(beans[i]);
        }
    }
    if(tmp[0]==tmp.back()) return 0;
    vector<long long>sum(tmp.size(),0);
    for (int i = 1; i < tmp.size(); ++i) {
        sum[i] = sum[i-1]+tmp[i-1];
    }

    long long ret = sum[beans.size()-1];
    vector<long long>diff(tmp.size(),0);

    for (int i = tmp.size()-2; i >=0; --i) {
        diff[i] = diff[i+1]+(tmp.size()-1-i)*(tmp[i+1]-tmp[i]);
        ret = min(ret,sum[i]+diff[i]);
    }
    return ret;
}



int main() {
    int num1 = 3,num2 = 2;
    int ret = countOperations(num1,num2);
    return 0;
}