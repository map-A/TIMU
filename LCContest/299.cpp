#include "bits/stdc++.h"

using namespace std;

bool checkXMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    for(int i=0;i<m;i++){
        if(grid[i][i]==0) return false;
    }
    for(int i=0;i<m;i++){
        if(grid[m-i-1][i]==0) return false;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(((i!=j)&&(i+j!=m-1))&&grid[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}
const int MOD = 1e9+7;
int countHousePlacements(int n) {
    long long n1 = 1,n2 = 2;
    long long n3;
    if(n==1) return 4;
    if(n==2) return 9;
    for(int i=2;i<=n;i++){
        n3  = (n1 + n2)% MOD;
        //cout<<n3;
        n1 = n2;
        n2 = n3;
    }


    return (long) n3* n3 % MOD;
}
int solve(vector<int> &nums1, vector<int> &nums2) {
    int s1 = reduce(nums1.begin(),nums1.end(),0), maxSum = 0;
    int s = 0;
    for (int i = 0; i < nums1.size(); ++i) {
        s = max(s + nums2[i] - nums1[i], 0);
        maxSum = max(maxSum, s);
    }
    return s1 + maxSum;
}
int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
    return max(solve(nums1, nums2), solve(nums2, nums1));
}


int main() {

    return 0;
}