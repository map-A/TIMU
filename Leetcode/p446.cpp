#include "bits/stdc++.h"

using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    int ret = 0;
    int n = nums.size();
    vector<unordered_map<long long,int>>dp(n);//dp(i)表示一nums[i]结尾,公差为longlong 的有int个
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            long long  d = nums[i]-nums[j];
            auto it = dp[j].find(d);
            int cnt =0;
            if(it!=dp[j].end()){
                cnt = it->second;
            }
            ret+=cnt;
            dp[i][d] += cnt+1;
        }
    }
    return ret;
}
int main() {

    return 0;
}