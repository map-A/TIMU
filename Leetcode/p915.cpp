#include "bits/stdc++.h"

using namespace std;

int partitionDisjoint(vector<int>& nums) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for (int i = 1; i < nums.size()-1; ++i) {
        pq.push({nums[i],i});
    }
    int ret = 1;
    int max_num = nums[0];
    int min_num = INT_MAX;
    pair<int,int>t;
    for (int i = 1; i < nums.size(); ++i) {
        if(pq.size()>1){
            t = pq.top();
            min_num = t.first;
        }
        while(pq.size()>0&&pq.top().second<=i){
            pq.pop();
        }


        if(max_num<=min_num){
            return ret;
        }
        max_num  = max(nums[i],max_num);
        ret++;
    }
    return ret;
}
int main() {
    vector<int>nums = {26,51,40,58,42,76,30,48,79,91};
    int ret = partitionDisjoint(nums);
  return 0;
}