#include "bits/stdc++.h"

using namespace std;
int eatenApples(vector<int>& apples, vector<int>& days) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //天数，这一天的苹果数
    int ret = 0;
    int i=0;
    for (; i < apples.size(); ++i) {
        if(apples[i]>0){
            pq.push({days[i]+i,apples[i]});
        }
        while (!pq.empty()&&pq.top().first<=i){
            pq.pop();
        }
        if(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            tmp.second--;
            ret++;
            if(tmp.second>0){
                pq.push(tmp);

            }
        }

    }
    while (!pq.empty()){
        while (!pq.empty()&&pq.top().first<=i){
            pq.pop();
        }
        if(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            tmp.second--;
            if(tmp.second>0){
                pq.push(tmp);
            }
            ret++;
        }
        i++;
    }
    return ret;
}
int main() {
    vector<int>apple = {1,2,3,5,2};
    vector<int>days = {3,2,1,4,2};
    auto ret = eatenApples(apple,days);
    return 0;
}