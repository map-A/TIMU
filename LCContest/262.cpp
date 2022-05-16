#include "bits/stdc++.h"

using namespace std;

vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    const int len = 101;
    int nums[len];
    memset(nums,0, sizeof(nums));
    sort(nums1.begin(), nums1.end());
    auto i1 = unique(nums1.begin(),nums1.end());
    nums1.erase(i1,nums1.end());
    for(auto i:nums1){
        nums[i]++;
    }
    sort(nums2.begin(), nums2.end());
    auto i2 = unique(nums2.begin(),nums2.end());
    nums2.erase(i2,nums2.end());
    for(auto i:nums2){
        nums[i]++;
    }

    sort(nums3.begin(), nums3.end());
    auto i3 = unique(nums3.begin(),nums3.end());
    nums3.erase(i3,nums3.end());
    for(auto i:nums3){
        nums[i]++;
    }
    vector<int>ret;
    for (int i = 0; i < len; ++i) {
        if(nums[i]>=2){
            ret.push_back(i);
        }
    }
    return ret;
}


int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size(),n = grid[0].size();
    const int len = m*n;
    int arr[len];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i*n+j] = grid[i][j];
        }
    }
    sort(arr,arr+len);
    int mid = arr[len/2];
    int sum = abs(mid-arr[0])/x;
    for(int i=1;i<len;i++){
        if((arr[i]-arr[i-1])%x!=0){
            return -1;
        }
        sum+= abs(mid-arr[i])/x;
    }
    return sum;
}

class StockPrice {
private:
    int time = INT_MIN;
    int cur = 0;
    priority_queue<pair<int,int>> que1;//存时间戳
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> que2;//存时间戳
    unordered_map<int, int> mp;//存对应价格
public:
    StockPrice() {

    }

    void update(int timestamp, int price) {
        if (timestamp >= time) {
            time = timestamp;
            cur = price;
        }
        mp[timestamp] = price;
        que1.push({price,timestamp});
        que2.push({ price,timestamp });
    }

    int current() {
        return cur;
    }

    int maximum() {
        auto m = que1.top();
        while (mp[m.second] != m.first) {
            que1.pop();
            m = que1.top();
        }
        return m.first;
    }

    int minimum() {
        auto m = que2.top();
        while (mp[m.second] != m.first) {
            que2.pop();
            m = que2.top();
        }
        return m.first;
    }
};


int main() {
    vector<int>nums1 = {1,1,3,2};
    vector<int>nums2 = {2,3};
    vector<int>nums3 = {3};
    auto ret = twoOutOfThree(nums1,nums2,nums3);
    return 0;
}