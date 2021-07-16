#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>>ret(m,vector<int>(n,0));
    vector<int>rowNow(m,0);
    vector<int>colNow(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int now=min(rowSum[i]-rowNow[i],colSum[j]-colNow[j]);
            ret[i][j]=now;
            rowNow[i]+=ret[i][j];
            colNow[j]+=ret[i][j];
        }
    }
    return ret;
}
int main() {
    vector<int>rowSum = {3,8};
    vector<int>colSum = {4,7};
    vector<vector<int>>ret = restoreMatrix(rowSum,colSum);
    return 0;
}