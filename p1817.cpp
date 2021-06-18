#include "bits/stdc++.h"

using namespace std;
vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int>ret(k+1,0);
    for(int i=0;i<logs.size();++i){
        ret[logs[i][0]]+=1;
        ret[logs[i][1]]-=1;
    }
    for(int i=1;i<k+1;k++){
        ret[i] +=ret[i-1];
    }
    return ret;
}
int main() {
    vector<vector<int>>logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    int k = 5;
    vector<int>ret = findingUsersActiveMinutes(logs,k);
    return 0;
}