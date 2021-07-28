#include "bits/stdc++.h"

using namespace std;

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

int main() {
    vector<vector<int>>times = {{1,4},{2,3},{4,6}};
    int targetFriend = 1;
    int ret  = smallestChair(times,targetFriend);
    return 0;
}
