#include "bits/stdc++.h"

using namespace std;

//BFS DFS
vector<pair<int, int>> directs = {{-1, 0},
                                  {1,  0},
                                  {0,  1},
                                  {0,  -1}};

void bst(int m, int n, vector<vector<int>> &vis, vector<vector<char>> &grid) {
    queue<pair<int, int>> q;
    int row = grid.size();
    int col = grid[0].size();
    q.push({m, n});
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            pair<int, int> pos = q.front();
            vis[pos.first][pos.second] = 1;
            q.pop();
            for (auto i:directs) {
                int x = pos.first + i.first;
                int y = pos.second + i.second;
                if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1' && vis[x][y] == 0) {
                    q.push({x, y});
                }
            }
        }
    }
}
int solve_with_bst(vector<vector<char> > &grid) {
    int ret = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1' && vis[i][j] == 0) {
                ret++;
                bst(i, j, vis, grid);
            }
        }
    }
    return ret;
}

void dfs(int m, int n, vector<vector<int>> &vis, vector<vector<char>> &grid) {
    int row = grid.size();
    int col = grid[0].size();
    vis[m][n] = 1;

    for (auto i:directs) {
        int x = m + i.first;
        int y = n + i.second;
        if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == '1' && vis[x][y] == 0) {
            dfs(x, y, vis, grid);
        }
    }
}


int solve_with_dfs(vector<vector<char> > &grid) {
    int ret = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == '1' && vis[i][j] == 0) {
                ret++;
                dfs(i, j, vis, grid);
            }
        }
    }
    return ret;
}

int main() {
    vector<vector<char>> grid = {{1, 1, 0, 0, 0},
                                 {0, 1, 0, 1, 1},
                                 {0, 0, 0, 1, 1},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 1, 1, 1}};
    int ret = solve_with_bst(grid);
    return 0;
}