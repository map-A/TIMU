#include "bits/stdc++.h"

using namespace std;
void solve(vector<int>&time,vector<vector<int>>&path){
    int n = path.size();
    vector<vector<int>>dp(n,vector<int>(n,INT_MAX/2));
    vector<vector<int>>p(n,vector<int>(n,INT_MAX/2));
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||path[i][j]<=0){
                dp[i][j] = INT_MAX/2;
            }
            else{
                dp[i][j] = path[i][j]+time[i];
                p[i][j] = j;
            }
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    cout<<dp[0][n-1];
}

int main() {
    int N = 0;
    scanf("%d\n",&N);
    vector<int>time;
    vector<vector<int>>path(N);
    string line;
    getline(cin, line);
    stringstream ss(line);
    string temp;
    while(getline(ss, temp, ' ')){
        time.push_back(stoi(temp));
    }
    for(int i=0;i<N;i++){
        getline(cin,line);
        stringstream ss(line);
        string temp;
        while(getline(ss, temp, ' ')){
            path[i].push_back(stoi(temp));
        }
    }
    solve(time,path);
    return 0;
}