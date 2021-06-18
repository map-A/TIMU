#include "bits/stdc++.h"

using namespace std;


/*
 * 对于第一个例子，ID=0在分钟5,2,5操作，认为其活跃非分钟数为2，因为有5，和2
 * ID=1 也是如此
 * 那么为什么answer[2]=2,其他的为0呢
 * 其实我们可以这么认为，活跃时间数目为2 ID有几个
 * 很明显这里有两个。
 *
 * 看看能不能解释示例1.
 * ID=1的用户活跃分钟数为1，ID=2的用户活跃分钟数为2
 * 那么活跃分钟的数目为1 的用户有ID=1这么一个人，活跃分钟数目为2的有ID=2这么一个人、
 * 其他数目没有，因此结果为[1,1,0,0]
 * */
vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    map<int,set<int>>m;
    for(auto &log : logs){
        m[log[0]].insert(log[1]);
    }

    vector<int> ret(k,0);
    for(auto &it:m){
        ret[it.second.size()-1]++;
    }
    return ret;
}

int main() {
    vector<vector<int>>logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    int k = 5;
    vector<int>ret = findingUsersActiveMinutes(logs,k);
    return 0;
}