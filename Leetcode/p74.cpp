//
// Created by mm on 2021/6/15 0015.
//

#include <bits/stdc++.h>

using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    for(int i=0;i<m;i++){
        if(binary_search(matrix[i].begin(),matrix[i].end(),target)){
            return true;
        }
        return false;
    }
}
int main(){
    vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout<<searchMatrix(matrix,target);
    return 0;
}