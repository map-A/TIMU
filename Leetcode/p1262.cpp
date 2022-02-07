#include "bits/stdc++.h"

using namespace std;
int maxSumDivThree(vector<int>& nums) {
    vector<vector<int>>tmp(3);
    for (int i = 0; i < nums.size(); ++i) {
        tmp[nums[i]%3].push_back(nums[i]);
    }
    int ret = accumulate(tmp[0].begin(),tmp[0].end(),0);
    //尽可能选大的
    sort(tmp[1].begin(),tmp[1].end(),greater());
    sort(tmp[2].begin(),tmp[2].end(),greater());
    int tt = 0;
    int len_1 = tmp[1].size();
    int len_2 = tmp[2].size();

    for (int i = len_1-2; i <= len_1; ++i) {
        if(i>=0){
            for (int j = len_2-2; j <=len_2; ++j) {
                if(j>=0&&(i)%3==(j)%3){
                    tt= max(tt, accumulate(tmp[1].begin(),tmp[1].begin()+i,0)+
                            accumulate(tmp[2].begin(),tmp[2].begin()+j,0)
                    );
                }
            }
        }
    }
    return ret+tt;
}
int main() {
    vector<int>nums = {1,2,3,4,4};
    int ret = maxSumDivThree(nums);
    return 0;
}