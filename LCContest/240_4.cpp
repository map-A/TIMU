#include "bits/stdc++.h"

using namespace std;

void solve(vector<int>&v,vector<int>&w,const int pow){
    vector<int>dp(pow+1,0);
    for(int i=0;i<v.size();i++){
        for(int j=pow;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[pow];

}

int main() {
    int powValue;
    cin>>powValue;
    int nums;
    cin>>nums;
    vector<int>v(nums);
    for(int i=0;i<nums;i++){
        cin>>v[i];
    }
    int nums2;
    cin>>nums2;
    vector<int>w(nums2);
    for(int i=0;i<nums2;i++){
        cin>>w[i];
    }
    solve(v,w,powValue);
    return 0;
}