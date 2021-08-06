#include "bits/stdc++.h"

using namespace std;
long long combine(vector<int>&nums){
    int sum = accumulate(nums.begin(),nums.end(),0);
    string strNum;
    for(int i=nums.size()-1;i>=0;i--){
        for(int j=0;j<nums[i];j++){
            strNum+=to_string(i);
        }
    }
    string a,b;
    for(int i=0;i<strNum.size();){
        a+=strNum[i];
        if(i+1<strNum.size()){
            b+=strNum[i+1];
        }
        i+=2;
        swap(a,b);
    }
    if(stoi(b)==0||stoi(a)==0){
        return stoi(strNum);
    }
    return (long long )stoi(a)*stoi(b);
}


int main() {

    vector<int>nums(10);
    cin>>nums[0]>>nums[1]>>nums[2]>>nums[3]>>nums[4]>>nums[5]>>nums[6]>>nums[7]>>nums[8]>>nums[9];
    long long ret = combine(nums);
    cout<<ret;
    return 0;
}



class Solution {
public:
    int maxGroupNumber(vector<int>& tiles) {
        map<int, int> count;  // [点数, 对应的牌数]，C++中的map是按照key(点数)从小到大排列的。
        for (auto tile : tiles)
            count[tile]++;

        vector<vector<int>> dp(5, vector<int>(5, -1));
        dp[0][0] = 0;
        int prev_tile = 0;
        for (auto [tile, cnt] : count) {
            if (prev_tile != tile - 1) {
                int dp00 = dp[0][0];
                dp = vector<vector<int>>(5, vector<int>(5, -1));
                dp[0][0] = dp00;
            }
            vector<vector<int>> new_dp(5, vector<int>(5, -1));

            for (int cnt_2 = 0; cnt_2 < 5; ++cnt_2) // [tile-2] 的牌数
                for (int cnt_1 = 0; cnt_1 < 5; ++cnt_1) { // [tile-1] 的牌数
                    if (dp[cnt_2][cnt_1] < 0)
                        continue;

                    for (int shunzi = 0; shunzi <= min(cnt_2, min(cnt_1, cnt)); ++shunzi) {
                        int new_2 = cnt_1 - shunzi;
                        for (int new_1 = 0; new_1 <= min(4, cnt - shunzi); ++new_1) {

                            int new_score = dp[cnt_2][cnt_1] + shunzi + (cnt - shunzi - new_1) / 3;
                            new_dp[new_2][new_1] = max(new_dp[new_2][new_1], new_score);
                        }
                    }
                }
            dp = move(new_dp);
            prev_tile = tile;
        }

        int ans = 0;
        for (int cnt_2 = 0; cnt_2 < 5; ++cnt_2)
            for (int cnt_1 = 0; cnt_1 < 5; ++cnt_1)
                ans = max(ans, dp[cnt_2][cnt_1]);

        return ans;
    }
};










