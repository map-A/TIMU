#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if(m*n!=original.size()){
        return {};
    }
    vector<vector<int>>ret(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ret[i][j] = original[i*n+j];
        }
    }
    return ret;
}
int main() {
    vector<int>original = {1,2,3,4};
    auto ret = construct2DArray(original,2,2);

    return 0;
}