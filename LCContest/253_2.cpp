#include "bits/stdc++.h"

using namespace std;
int minStoneSum(vector<int>& piles, int k) {

    //初始化一个大顶堆
    priority_queue<int,vector<int>>p(piles.begin(),piles.end());
    while(k>0){
        int val = p.top();
        p.pop();
        k--;
        p.push(val-val/2);
    }
    int ret = 0;
    while(!p.empty()){
        ret+=p.top();
        p.pop();
    }
    return ret;
}
int main() {

    return 0;
}