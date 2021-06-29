#include "bits/stdc++.h"

using namespace std;
void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++){
        for(int j=i;j<matrix[0].size();++j){
            swap(matrix[i][j],matrix[j][i]);
        }
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
bool mat_eq(vector<vector<int>>& mat, vector<vector<int>>& target){
    int m = mat.size(),n = mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=target[i][j]) return false;
        }
    }
    return true;
}
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for(int i=0;i<4;i++){
        rotate(mat);
        if(mat_eq(mat,target)){
            return true;
        }
    }
    return false;
}

int main() {
    string num = "4205";
    return 0;
}