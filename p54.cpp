//
// Created by mm on 2021/6/14 0014.
//

#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> direct = {{0,  1},
                                 {1,  0},
                                 {0,  -1},
                                 {-1, 0}};

void dfs(int s, int t, vector<vector<int>> &matri, vector<vector<int>> &vis, vector<int> &ret, int &cyc) {
    int n = matri.size();
    int m = matri[0].size();
    if (ret.size() == m * n)return;
    if (s >= 0 && s < n && t >= 0 && t < m && vis[s][t] == 0) {
        ret.push_back(matri[s][t]);
        vis[s][t] = 1;
    }

    if (s + direct[cyc].first >= 0 && s + direct[cyc].first < n &&
        t + direct[cyc].second >= 0 && t + direct[cyc].second < m &&
        vis[s + direct[cyc].first][t + direct[cyc].second] == 0) {
        s = s + direct[cyc].first;
        t = t + direct[cyc].second;
    } else {
        cyc = (cyc + 1) % 4;
    }
    dfs(s, t, matri, vis, ret, cyc);
}

vector<int> spiralOrder1(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> ret;
    int cyc = 0;
    dfs(0, 0, matrix, vis, ret, cyc);
    return ret;
}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty()) return {};

    int m = matrix.size(), n = matrix[0].size();
    vector<int> ret;
    int left = 0, top = 0, right = n - 1, bottom = m - 1;
    while (left <right && top <bottom) {
        for (int i = left; i < right; i++) {
            ret.push_back(matrix[top][i]);
        }
        for (int i = top; i < bottom; i++) {
            ret.push_back(matrix[i][right]);
        }
        for (int i = right; i > left; i--) {
            ret.push_back(matrix[bottom][i]);
        }
        for (int i = bottom; i > top; i--) {
            ret.push_back(matrix[i][left]);
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    if(left==right&top==bottom){
        ret.push_back(matrix[left][top]);
    }
    else if(top==bottom){
        for (int i = left; i <=right; i++) {
            ret.push_back(matrix[top][i]);
        }
    }
    else if(left==right){
        for (int i = top; i <= bottom; i++) {
            ret.push_back(matrix[i][right]);
        }
    }
    return ret;
}


int main() {
    vector<vector<int>> matric = {{1, 2, 3},
    };
    vector<int> ret;
    ret = spiralOrder(matric);
    for (auto i :ret) {
        cout << i;
    }
    return 0;
}