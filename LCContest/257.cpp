#include "bits/stdc++.h"

using namespace std;
int countQuadruplets(vector<int>& nums) {
    int ret = 0;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(nums[i] + nums[j] + nums[k] == nums[l]) ret++;
                }
            }
        }
    }
    return ret;
}

int numberOfWeakCharacters(vector<vector<int>>& pr) {
    sort(pr.begin(),pr.end(),[&](auto &a,auto &b){
        return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];  //排序
    });
    int maxg=-1,num=0;
    for(auto i:pr){
        if(i[1]<maxg)
            num++;
        maxg=max(i[1],maxg);  //更新最大值
    }
    return num;
}



int main() {
    vector<int>nums = {1,2,3,6};
    int ret = countQuadruplets(nums);
    return 0;
}