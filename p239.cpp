//
// Created by mm on 2021/6/15 0015.
//

#include "bits/stdc++.h"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(k == 1) return nums;

    vector<int>ret;
    deque<int>q;
    for(int i=0;i<nums.size();++i){
        if(!q.empty()&&q.front()==i-k){
            q.pop_front();//开始右移一次
        }
        while(!q.empty()&&nums[i]>nums[q.back()]){
            q.pop_back();//维护队列的第一位永远是最大值，与新来的元素比较的时候，小于新来的，全部删掉。
        }
        q.push_back(i);//把新来的加入到队列里面。
        if(i>=k-1){
            ret.push_back(nums[q.front()]);
        }
    }
    return ret;
}
int main() {
    vector<int> nums= {1,3,-1,-3,5,3,6,7};
    int k =3;
    vector<int>ret = maxSlidingWindow(nums,k);
    for(auto i:ret){
        cout<<i;
    }
    return 0;
}