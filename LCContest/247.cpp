#include "bits/stdc++.h"

using namespace std;
int maxProductDifference(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n-1]*nums[n-2]-(nums[0]*nums[1]);
}

vector<pair<int,int>>direct = {{0,1},{1,0},{0,-1},
                               {-1,0}};
void dfs(int s,int t,vector<vector<int>>&matri,vector<vector<int>>&vis,vector<int>&ret,int &cyc){
    int n = matri.size();
    int m = matri[0].size();
    if(ret.size()==m*n)return;
    if(s>=0&&s<n&&t>=0&&t<m&&vis[s][t]==0){
        ret.push_back(matri[s][t]);
        vis[s][t]=1;
    }

    if(s+direct[cyc].first>=0&&s+direct[cyc].first<n&&
       t+direct[cyc].second>=0&&t+direct[cyc].second<m&&
       vis[s+direct[cyc].first][t+direct[cyc].second]==0){
        s = s+direct[cyc].first;
        t = t+direct[cyc].second;
    }
    else{
        cyc = (cyc+1)%4;
    }
    dfs(s,t,matri,vis,ret,cyc);
}
void dfs2Ret(int s,int t,vector<vector<int>>&matri,vector<vector<int>>&vis,vector<int>&ret,int &cyc,int i){
    int n = matri.size();
    int m = matri[0].size();
    if(i==m*n)return;
    if(s>=0&&s<n&&t>=0&&t<m&&vis[s][t]==0){
        matri[s][t]=ret[i];
        vis[s][t]=1;
        i++;
    }

    if(s+direct[cyc].first>=0&&s+direct[cyc].first<n&&
       t+direct[cyc].second>=0&&t+direct[cyc].second<m&&
       vis[s+direct[cyc].first][t+direct[cyc].second]==0){
        s = s+direct[cyc].first;
        t = t+direct[cyc].second;
    }
    else{
        cyc = (cyc+1)%4;
    }
    dfs2Ret(s,t,matri,vis,ret,cyc,i);

}
int main() {
   vector<int>nums ={ 4,2,5,9,7,4,8};
    int ret = maxProductDifference(nums);
    return 0;
}