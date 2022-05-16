#include "bits/stdc++.h"

using namespace std;
int toNum(string s){
    string tmp;
    for(auto i:s){
        tmp+= to_string(i-'a');
    }
    int ret = stoi(tmp);
    return ret;
}
bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    int a = toNum(firstWord);
    int b = toNum(secondWord);
    int c = toNum(targetWord);
    return a+b==c;
}


string maxValue(string n, int x) {
    //检查是否为负数
    int flag = 1;
    if(n[0]=='-') flag=-1;
    if(flag==1){
        //正数的情况
        int i;
        for(i=0;i<n.size();i++){
            //找到第一个比x小的位置,在其前面插入
            if(n[i]-'0'<x){
                n.insert(i,to_string(x));
                break;
            }
        }
        if(i==n.size())n.append(to_string(x));
    }
    else{
        //负数的情况
        int i;
        for(i=1;i<n.size();i++){
            //找到第一个比x大的位置
            if(n[i]-'0'>x){
                n.insert(i,to_string(x));
                break;
            }
        }
        if(i==n.size()){
            n.insert(i,to_string(x));
        }
    }
    return n;
}


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
    string firstWord = "acb";
    string secondWord = "cba";
    string targetWord = "cdb";
    bool ret =isSumEqual(firstWord,secondWord,targetWord);
    return 0;
}