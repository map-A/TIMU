#include "bits/stdc++.h"

using namespace std;
int countKDifference(vector<int>& nums, int k) {
    int ret = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[i]-nums[j])==k){
                ret++;
            }
        }
    }
    return ret;
}


vector<int> findOriginalArray(vector<int>& changed) {
    if(changed.size()%2!=0) return {};
    vector<int>vis(100010,0);
    int c[100010];
    //memset 是按照字节赋值，int是4个字节，char是一个字节，并且只能赋值为0，或者1、
    memset(c,0, sizeof(int)*100010);
    for(int i=0;i<changed.size();i++){
        vis[changed[i]]++;
    }
    vector<int>ret;
    for(int i=0;i<vis[0]/2;i++){
        ret.push_back(0);
    }
    for(int i=1;i<vis.size()/2;i++){
        int tmp = vis[i];
        for(int j=0;j<tmp;j++){
            if(vis[i]>0&&vis[2*i]>0){
                vis[i]--;
                vis[2*i]--;
                ret.push_back(i);
            }
            else if(vis[i]>0&&vis[2*i]<=0){
                return {};
            }
            if(ret.size()==changed.size()/2) return ret;
        }
    }
    if(ret.size()==changed.size()/2) return ret;
    return {};
}


static bool cmp(vector<int> & v1, vector<int> & v2) {
    return v1[0] < v2[0];
}
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end(), cmp);
    vector<long long> dp(n+1,0);  // 在i的位置最多可以赚多少
    int start = 0;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i], dp[i + 1]);
        if(start != rides.size()&& rides[start][0] == i) { // 在这个地方有人可以接
            dp[rides[start][1]] = max(dp[rides[start][1]], dp[i] + rides[start][2] + rides[start][1] - rides[start][0]);
            start++;
            i--;
        }

    }
    return dp[n];
}





int main() {

    return 0;
}