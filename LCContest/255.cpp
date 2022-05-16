#include "bits/stdc++.h"

using namespace std;
int findGCD(vector<int>& nums) {

    int min_num = *min_element(nums.begin(),nums.end());
    int max_num = *max_element(nums.begin(),nums.end());
    int ret = gcd(min_num,max_num);
    return ret;
}

string findDifferentBinaryString(vector<string>& nums) {
    sort(nums.begin(),nums.end());
    unique(nums.begin(),nums.end());
    int n = nums[0].size();
    int index = 0;
    for(int i=0;i<nums.size();i++){
        bitset<16>a(nums[i]);
        if(a==index){
            index++;
        }
        else{
            bitset<16>c(index);
            return c.to_string();
        }
    }

}


int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int max_sum = 0;
    vector<int>f = {1};
    for(int i=0;i<m;i++){
        int max_num = *max_element(mat[i].begin(),mat[i].end());
        vector<int>g(max_num+max_sum+1);
        for(auto x:mat[i]){
            for(int j=x;j<=max_sum+x;j++){
                g[j]|=f[j-x];
            }
        }
        f = move(g);
        max_sum+=max_num;
    }
    int ret = INT_MAX;
    for(int i=0;i<=max_sum;i++){
        if(f[i]&&abs(i-target)<ret){
            ret = abs(i-target);
        }
    }
    return ret;

}
int main() {

    return 0;
}