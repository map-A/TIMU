#include "bits/stdc++.h"

using namespace std;
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

    for(int i=1;i<arr.size();i++){
        arr[i] = arr[i]^arr[i-1];
    }
    vector<int>ret(queries.size(),0);
    for(int i=0;i<queries.size();i++){
        if(queries[i][0]==0){
            ret[i] = arr[queries[i][1]];
        }
        else{
            ret[i] = arr[queries[i][0]-1]^arr[queries[i][1]];

        }
    }
    return ret;
}
int main() {
    vector<int>arr = {1,3,4,8};
    vector<vector<int>>queries = {{0,1},{1,2},{0,3},{3,3}};
    vector<int>ret = xorQueries(arr,queries);
    return 0;
}