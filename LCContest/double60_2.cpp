#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int rows = land.size(), cols = land[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(land[i][j] == 1 && (i - 1 < 0 || land[i-1][j] == 0) && (j - 1 < 0 || land[i][j-1] == 0)) {
                int x = i + 1, y = j + 1;
                while(y < cols && land[i][y] == 1)  ++y;
                while(x < rows && land[x][j] == 1) ++x;
                ans.push_back({i, j, x - 1, y - 1});
            }
        }
    }
    return ans;
}
int main() {

    return 0;
}