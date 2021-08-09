#include "bits/stdc++.h"

using namespace std;

//最长上升子序列
int lengthOfLIS(vector<int>& nums) {
    int ret = 0,n = nums.size();
    vector<int>lis(n);
    //初始化一维dp表格
    for(int i = 0;i<n;i++)
        lis[i] = 1;
    //自底向上规划
    for (int i = 1;i<n;i++)
        for (int j=0;j<i;j++)
    if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
    //找最大值
    for(int i=0;i<n;i++){
        if(ret<lis[i])ret=lis[i];
    }
    return ret;
}
int main() {

    return 0;
}