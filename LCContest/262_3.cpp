#include "bits/stdc++.h"

using namespace std;

class StockPrice {
private:
    int time = INT_MIN;
    int cur = 0;
    priority_queue<pair<int,int>> que1;//存时间戳
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> que2;//存时间戳
    unordered_map<int, int> mp;//存对应价格
public:
    StockPrice() {

    }

    void update(int timestamp, int price) {
        if (timestamp >= time) {
            time = timestamp;
            cur = price;
        }
        mp[timestamp] = price;
        que1.push({price,timestamp});
        que2.push({ price,timestamp });
    }

    int current() {
        return cur;
    }

    int maximum() {
        auto m = que1.top();
        while (mp[m.second] != m.first) {
            que1.pop();
            m = que1.top();
        }
        return m.first;
    }

    int minimum() {
        auto m = que2.top();
        while (mp[m.second] != m.first) {
            que2.pop();
            m = que2.top();
        }
        return m.first;
    }
};
