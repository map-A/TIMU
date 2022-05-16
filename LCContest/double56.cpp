#include "bits/stdc++.h"

using namespace std;

int countTriples(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sq = i * i + j * j;
            int t = (int) sqrt(sq);

            if (t <= n && t * t == sq) {
                ret++;
            }
        }
    }
    return ret * 2;
}


int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    //先扫一圈有没有出口
    set<pair<int, int>> out;
    int m = maze.size();
    int n = maze[0].size();
    for (int i = 0; i < n; i++) {
        if (maze[0][i] == '.') {
            out.insert({0, i});
        }
        if (maze[m - 1][i] == '.') {
            out.insert({m - 1, i});
        }
    }
    for (int i = 0; i < m; i++) {
        if (maze[i][0] == '.') {
            out.insert({i, 0});
        }
        if (maze[i][n - 1] == '.') {
            out.insert({i, n - 1});
        }
    }
    if (out.find({entrance[0], entrance[1]}) != out.end() && out.size() == 1 || out.empty()) {
        return -1;
    }
    out.erase({entrance[0], entrance[1]});
    //在起始的位置进行广搜

    bool visit[m][n];
    memset(visit, false, sizeof(visit));
    int dir[][2] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});

    visit[entrance[0]][entrance[1]] = true;
    int ret = INT_MAX;
    int tmp = 0;
    while (!q.empty()) {
        tmp++;
        int len = q.size();
        for (int j = 0; j <len; j++) {
            pair<int, int> vn = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> new_t = {vn.first + dir[i][0], vn.second + dir[i][1]};
                if (new_t.first < m && new_t.first >= 0 && new_t.second < n && new_t.second >= 0) {
                    if (out.find(new_t) != out.end()) {
                        ret = min(ret, tmp);
                    }
                    if (maze[new_t.first][new_t.second] == '.' && visit[new_t.first][new_t.second] == false) {
                        q.push(new_t);
                        visit[new_t.first][new_t.second] = true;
                    }
                }

            }

        }

    }
    return ret == INT_MAX ? -1 : ret;
}


bool sumGame(string num) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] == '?')count++;
        else sum += num[i] - '0';
    }

    for (int i = num.size() / 2; i < num.size(); i++) {
        if (num[i] == '?')count--;
        else sum -= num[i] - '0';
    }
    if (count % 2 == 0 && sum + count * 9 / 2 == 0) {
        return false;
    }
    return true;
}

int minCost(int maxTime,vector<vector<int>>&edges,vector<int>passingFees){
    int n = passingFees.size();
    vector<vector<int>>dp(maxTime+1,vector<int>(n,INT_MAX/2));
    dp[0][0] = passingFees[0];
    for(int i=1;i<=maxTime;i++){
        for(auto &edge:edges){
            int s = edge[0],t = edge[1],cost = edge[2];
            if(cost<=i){
                dp[i][s] = min(dp[i][s],dp[i-cost][t]+passingFees[s]);
                dp[i][t] = min(dp[i][t],dp[i-cost][s]+passingFees[t]);
            }
        }
    }
    int ret = INT_MAX/2;
    for(int i=1;i<=maxTime;i++){
        ret = min(ret,dp[i][n-1]);
    }
    return ret==INT_MAX/2?-1:ret;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}