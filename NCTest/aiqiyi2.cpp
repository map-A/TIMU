#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> PII;
vector<int> func(vector<int> &rains) {
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> heap;
    unordered_map<int, int> mp;
    vector<pair<int, PII>> ret;
    int n = rains.size();
    for (int i = 0; i < n; i++) {
        int x = rains[i];
        if (!x) continue;
        if (mp.count(x)) {
            if (mp[x] == i - 1) return vector<int>();
            ret.push_back({mp[x] + 1, {i - 1, x}});
        }
        mp[x] = i;
    }
    sort(ret.begin(), ret.end());
    vector<int> final_ret;
    int j = 0;
    int m = ret.size();
    for (int i = 0; i < n; i++) {
        int x = rains[i];
        while (j < m) {
            if (ret[j].first <= i) {
                heap.push({ret[j].second.first, {ret[j].first, ret[j].second.second}});
                j++;
            } else {
                break;
            }
        }
        if (x != 0) final_ret.push_back(-1);
        else {
            if (heap.size()) {
                auto elem = heap.top();
                heap.pop();
                if (elem.first < i) return vector<int>();
                else {
                    final_ret.push_back(elem.second.second);
                }
            } else {
                final_ret.push_back(1);
            }
        }
    }
    if (heap.size()) return vector<int>();
    else return final_ret;
}

int main() {
    string line;
    vector<int> vec;
    string temp;
    getline(cin, line);
    stringstream ss(line.substr(1,line.length()-2));
    while(getline(ss, temp, ',')){
        vec.push_back(stoi(temp));
    }
    auto ret = func(vec);
    cout<<'[';
    for(int i=0;i<ret.size()-1;i++){
        cout<<ret[i]<<',';
    }
    cout<<ret[ret.size()-1]<<']';
    return 0;
}