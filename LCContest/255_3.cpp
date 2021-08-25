#include "bits/stdc++.h"

using namespace std;
//背包

int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int max_sum = 0;
    vector<int>f = {1};
    for(int i=0;i<m;i++){
        int max_num = *max_element(mat[i].begin(),mat[i].end());
        vector<int>g(max_num+max_sum+1);
        for(auto x:mat[i]){
            for(int j=x;j<=max_sum+x;j++){
                g[j]|=f[j-x];
            }
        }
        f = move(g);
        max_sum+=max_num;
    }
    int ret = INT_MAX;
    for(int i=0;i<=max_sum;i++){
        if(f[i]&&abs(i-target)<ret){
            ret = abs(i-target);
        }
    }
    return ret;

}
int main() {

    return 0;
}