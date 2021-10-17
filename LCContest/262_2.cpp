#include "bits/stdc++.h"

using namespace std;
int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size(),n = grid[0].size();
    const int len = m*n;
    int arr[len];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i*n+j] = grid[i][j];
        }
    }
    sort(arr,arr+len);
    int mid = arr[len/2];
    int sum = abs(mid-arr[0])/x;
    for(int i=1;i<len;i++){
        if((arr[i]-arr[i-1])%x!=0){
            return -1;
        }
        sum+= abs(mid-arr[i])/x;
    }
    return sum;
}

int main() {

    return 0;
}