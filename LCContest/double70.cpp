#include "bits/stdc++.h"

using namespace std;
int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end(),greater<int>());
    int ret = accumulate(cost.begin(),cost.end(),0);
    for (int i = 2; i < cost.size(); i+=3) {
        ret-=cost[i];
    }
    return ret;
}


int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long l = lower,r  = upper;
    long long t = 0;
    for (int i = 0; i < differences.size(); ++i) {
        t+=differences[i];
        l = max(l,lower+t);
        r = min(r,upper+t);
    }
    return r-l+1>0?r-l+1:0;
}


static constexpr int dx[4] = {1, 0, -1, 0};
static constexpr int dy[4] = {0, 1, 0, -1};

vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
    vector<tuple<int, int, int, int>> items;   // 感兴趣物品的信息
    queue<tuple<int, int, int>> q;   // 广度优先搜索队列
    q.emplace(start[0], start[1], 0);
    if (pricing[0] <= grid[start[0]][start[1]] && grid[start[0]][start[1]] <= pricing[1]) {
        items.emplace_back(0, grid[start[0]][start[1]], start[0], start[1]);
    }
    int m = grid.size(),n = grid[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    vis[start[0]][start[1]] = 1;
    while (!q.empty()) {
        auto[x, y, d] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            // 遍历相邻坐标，并进行对应操作
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > 0&&vis[nx][ny]==0) {
                if (pricing[0] <= grid[nx][ny] && grid[nx][ny] <= pricing[1]) {
                    items.emplace_back(d + 1, grid[nx][ny], nx, ny);
                }
                q.emplace(nx, ny, d + 1);
                vis[nx][ny] = 1;   // 避免重复遍历
            }
        }
    }
    sort(items.begin(), items.end());   // 按照优先级从高到低排序
    vector<vector<int>> ret;   // 排名最高 k 件物品的坐标
    int cnt = min(k,(int)items.size());
    for (int i = 0; i < cnt; ++i) {
        auto[d, price, x, y] = items[i];
        ret.push_back({x, y});
    }
    return ret;
}


int main() {

    vector<int>cost = {1,2,3};
    int ret = minimumCost(cost);
    return 0;
}