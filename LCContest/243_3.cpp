#include "bits/stdc++.h"

using namespace std;
using  PIL= pair<long long,int>;
using PII = pair<int,int>;
bool operator > (vector<int>&a,vector<int>&b)
{
    if(a[2]>b[2]) return true;
    else if(a[2]<b[2]) return false;
    else{
        return a[0]>b[0];
    }
}
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    //权重，下表，可使用的时间
    //可使用
    //有限选择可使用，并且对齐到现在的时间
    int n = tasks.size();
    priority_queue<PIL,vector<PIL>,greater<PIL>>busy;
    priority_queue<PII,vector<PII>,greater<PII>>idle;
    for(int i=0;i<servers.size();i++){
        idle.emplace(servers[i],i);
    }
    long long ts = 0;
    vector<int>ret;
    for(int i=0;i<n;i++){
        ts = max(ts,static_cast<long long >(i));
        while(!busy.empty()&&busy.top().first<=ts){
            PIL tmp = busy.top();
            idle.emplace(servers[tmp.second],tmp.second);
            busy.pop();
        }
        if(idle.empty()){
            ts = busy.top().first;
            while(!busy.empty()&&busy.top().first<=ts){
                PIL tmp = busy.top();
                idle.emplace(servers[tmp.second],tmp.second);
                busy.pop();
            }
        }
        PII p = idle.top();
        ret.push_back(p.second);
        busy.emplace(ts+tasks[i],p.second);
        idle.pop();
    }
    return ret;
}
int main() {
    vector<int>server = {10,63,95,16,85,57,83,95,6,29,71};
    vector<int>tasks = {70,31,83,15,32,67,98,65,56,48,38,90,5};
    vector<int>ret =  assignTasks(server,tasks);
    return 0;
}