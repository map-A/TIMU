#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> dirs = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

void BFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, bool &flag) {
    int m = grid2.size(), n = grid2[0].size();
    queue<vector<int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            for (auto dir:dirs) {
                int x = q.front()[0] + dir[0];
                int y = q.front()[1] + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1) {
                    q.push({x, y});
                    grid2[x][y] = 0;

                }
            }
            if (grid1[q.front()[0]][q.front()[1]] == 0 && flag == true) {
                flag = false;
            }
            q.pop();
        }
    }
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    if (grid2.size() == 0) return 0;
    int m = grid2.size(), n = grid2[0].size();
    //vector<vector<int>>visit(m,vector<int>(n,0));
    int ret = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                bool flag = true;
                grid2[i][j]=0;
                BFS(grid1, grid2, i, j, flag);
                if (flag == true)
                    ret++;
            }
        }
    }
    return ret;

}

int main() {
    vector<vector<int>> grid1 = {{1, 1, 1, 0, 0},
                                {0, 1, 1, 1, 1},
                                {0, 0, 0, 0, 0},
                                {1, 0, 0, 0, 0},
                                {1, 1, 0, 1, 1}},
            grid2 = {{1, 1, 1, 0, 0},
                     {0, 0, 1, 1, 1},
                     {0, 1, 0, 0, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 1, 0}};
    auto ret = countSubIslands(grid1,grid2);
    return 0;
}