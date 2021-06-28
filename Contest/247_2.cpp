#include "bits/stdc++.h"

using namespace std;
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

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>ret;
    int cyc = 0;
    dfs(0,0,grid,vis,ret,cyc);

    //吧这些数填进去
    int start = 0;
    int tmp = k;
    while(m>0&&n>0){
        int len = 0;
        len = m*2+(n-2)*2;
        k = tmp%len;
       reverse(ret.begin()+start,ret.begin()+start+k);
       reverse(ret.begin()+start+k,ret.begin()+start+len);
       reverse(ret.begin()+start,ret.begin()+start+len);
       m = m-2;
       n = n-2;
       start += len;
    }
     n = grid.size();
    m = grid[0].size();
    vector<vector<int>>vis2(n,vector<int>(m,0));
    cyc = 0;
    dfs2Ret(0,0,grid,vis2,ret,cyc,0);
    return grid;
}
int main() {
    vector<vector<int>>grid ={{3970,1906,3608,298,3072,3546,1502,773,4388,3115,747,3937},
                              {2822,304,4179,1780,1709,1058,3645,681,2910,2513,4357,1038},
                              {4471,2443,218,550,2766,4780,1997,1672,4095,161,4645,3838},
                              {2035,2350,3653,4127,3208,4717,4347,3452,1601,3725,3060,2270},
                              {188,2278,81,3454,3204,1897,2862,4381,3704,2587,743,3832},
                              {996,4499,66,2742,1761,1189,608,509,2344,3271,3076,108},
                              {3274,2042,2157,3226,2938,3766,2610,4510,219,1276,3712,4143},
                              {744,234,2159,4478,4161,4549,4214,4272,701,4376,3110,4896},
                              {4431,1011,757,2690,83,3546,946,1122,2216,3944,2715,2842},
                              {898,4087,703,4153,3297,2968,3268,4717,1922,2527,3139,1516},
                              {1086,1090,302,1273,2292,234,3268,2284,4203,3838,2227,3651},
                              {2055,4406,2278,3351,3217,2506,4525,233,3829,63,4470,3170},
                              {3797,3276,1755,1727,1131,4108,3633,1835,1345,1293,2778,2805},
                              {1215,84,282,2721,2360,2321,1435,2617,1202,2876,3420,3034}};

    int k = 405548684;
    auto ret =rotateGrid(grid,k);

    return 0;
}

