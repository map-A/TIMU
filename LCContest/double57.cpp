#include "bits/stdc++.h"

using namespace std;

typedef long long LL;

bool areOccurrencesEqual(string s) {
    int ch[26]={0};
    //memset(ch,0,26);
    for (int i=0;i<s.size();i++){
        ch[s[i]-'a']++;
    }
    int cnt = 0;
    for (int i : ch){
        if(i!=0&&cnt==0){
            cnt = i;
        }
       if(i!=0&&cnt!=i) return false;
    }
    return true;
}



typedef long long LL;
struct cmp{
    bool operator () (pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }
};
int smallestChair(vector<vector<int>>& times, int targetFriend) {
    priority_queue<int,vector<int>,greater<int>>pos;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>c;//时间-座位
    for(int i=0;i<times.size();i++){
        pos.push(i);
    }

    vector<int>tmp  = times[targetFriend];
    sort(times.begin(),times.end());
    for(auto t:times){
        int i_time = t[0];
        int o_time = t[1];
        while(!c.empty()&&c.top().first<=i_time){
            //当有人可以在i_time之前离开
            pos.push(c.top().second);
            c.pop();
        }
        //当前时间等于目标时间，返回pos的堆顶
        if(i_time==tmp[0]) return pos.top();
        //而当没有人离开，指在c的堆顶均在这个人到来之后离开
        //加入新来的人以及离开的时间，并把这个可用的椅子分配给c，pos堆顶删除，表示不可用
        c.push({o_time,pos.top()});
        pos.pop();
    }
    return 0;
}


#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    map<int,long long>m;
    for(auto segment:segments){
        m[segment[0]] +=segment[2];
        m[segment[1]]-=segment[2];
    }
    vector<vector<long long>>ret;
    long long color= 0;
    long long left = 0,right = 0;
    for(auto i:m){
        right = i.first;
        if(color!=0){
            ret.push_back({left,right,color});
        }
        left = right;
        color+=i.second;
    }
    return ret;
}


vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ret(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty()) {
            ++ret[i];
            if (heights[i] > heights[s.top()]) {
                s.pop();
            }
            else {
                break;
            }
        }
        s.push(i);
    }
    return ret;
}




int main() {
    string s = "abacbc";
    bool ret = areOccurrencesEqual(s);
    return 0;
}
