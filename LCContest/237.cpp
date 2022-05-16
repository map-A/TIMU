#include "bits/stdc++.h"

using namespace std;
bool checkIfPangram(string sentence) {
    bool vis[26];
    memset(vis,false,sizeof(vis));
    for(auto i:sentence){
        vis[i-'a'] =1;
    }
    for(int i=0;i<26;i++){
        if(vis[i]==0) return false;
    }
    return true;
}

int maxIceCream(vector<int>& costs, int coins) {
    int ret = 0;
    sort(costs.begin(),costs.end());
    for(int i=0;i<costs.size();++i){
        if(costs[i]<=coins){
            coins-=costs[i];
            ret++;
        }
        else{
            break;
        }
    }
    return ret;
}


using PII = pair<int, int>;
using LL = long long;

vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return tasks[i][0] < tasks[j][0];
    });
    vector<int> ret;
    // 优先队列
    priority_queue<PII, vector<PII>, greater<PII>> q;
    // 时间戳
    LL timestamp = 0;
    // 数组上遍历的指针
    int ptr = 0;

    for (int i = 0; i < n; ++i) {
        // 如果没有可以执行的任务，直接快进
        if (q.empty()) {
            timestamp = max(timestamp, (LL) tasks[indices[ptr]][0]);
        }
        // 将所有小于等于时间戳的任务放入优先队列
        while (ptr < n && tasks[indices[ptr]][0] <= timestamp) {
            q.emplace(tasks[indices[ptr]][1], indices[ptr]);
            ++ptr;
        }
        // 选择处理时间最小的任务
        auto&&[process, index] = q.top();
        timestamp += process;
        ret.push_back(index);
        q.pop();
    }

    return ret;
}

int main() {
    string sentence = "Leetcode";
    bool ret = checkIfPangram(sentence);
    return 0;
}