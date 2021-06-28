#include "bits/stdc++.h"

using namespace std;

bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    vector<int>vis(51,0);
    for(int i=0;i<ranges.size();i++){
        for(int j=ranges[i][0];j<=ranges[i][1];j++){
            vis[j] = 1;
        }
    }
    for(int j=left;j<=right;j++){
        if(vis[j]==0) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> range = {{1, 2},
                                 {3, 4},
                                 {5, 6}};
    int left = 2, right = 5;
    bool ret = isCovered(range, left, right);
    return 0;
}