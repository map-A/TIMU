#include "bits/stdc++.h"

using namespace std;
int bagOfTokensScore(vector<int>& tokens, int power) {
    set<int>s;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq2;
    for (int i = 0; i < tokens.size(); ++i) {
        pq1.push({tokens[i],i});
        pq2.push({tokens[i],i});

    }
    int grade = 0;
    int ret = 0;

    while (!pq1.empty()){
        int tmp = grade;
        int pq1_size=pq1.size();
        if(s.find(pq1.top().second)==s.end()){
            if(pq1.top().first<= power){
                power-=pq1.top().first;
                grade++;
                ret = max(ret,grade);
                s.insert(pq1.top().second);
                pq1.pop();

            }
            else{
                if(grade>0&&!pq2.empty()){
                    if(s.find(pq2.top().second)==s.end()){
                        power+=pq2.top().first;
                        grade--;
                        s.insert(pq2.top().second);
                    }
                    pq2.pop();
                }
            }
        }
        else {
            pq1.pop();
        }
        if(pq1.size()==pq1_size&&tmp==grade){
            return ret;
        }
    }
    return ret;
}
int main() {
    vector<int>tokens = {100,200,300,400};
    int power = 200;
    int ret = bagOfTokensScore(tokens, power);
    return 0;
}