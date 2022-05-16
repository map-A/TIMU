#include "bits/stdc++.h"

using namespace std;
int minTimeToType(string word) {
    char pre = 'a';
    int ret = word.size();
    for(auto i:word){
        ret+=min(abs(i-pre-26)%26,abs(i-pre+26)%26);
        pre = i;
    }
    return ret;
}

long long maxMatrixSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    long long ret = 0;
    vector<int> minus(m, INT_MAX);
    int minus_count = 0;
    for (int i = 0; i < m; i++) {
        //找到每一行里面的负数个数
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                minus_count++;
            }
            ret += abs(matrix[i][j]);
            minus[i] = min(abs(matrix[i][j]), minus[i]);

        }
    }
    int t = *min_element(minus.begin(), minus.end());
    if (minus_count % 2 == 0) {
        return ret;
    } else {
        return ret - 2 * (t);
    }
}




// 多源最短路径算法
int mod = 1e9+7;
vector<vector<long long>> floydWarshall(vector<vector<long long >> &path) {
    int n = path.size();
    vector<vector<long long>> dist(n,vector<long long>(n,LLONG_MAX/2));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = path[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != LLONG_MAX/2  && dist[i][k] != LLONG_MAX/2))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}

int countPaths(int n, vector<vector<int>> &roads) {
    if(roads.empty()) return 1;
    vector<vector<long long>> path(n, vector<long long >(n, LLONG_MAX/2));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (auto i:roads) {
        path[i[0]][i[1]] =(long long ) i[2];
        path[i[1]][i[0]] = (long long )i[2];
    }

    vector<vector<long long>> dist = floydWarshall(path);
    for(auto i:roads){
        if(i[2]==dist[i[0]][i[1]]){
            dp[i[0]][i[1]] = 1;
            dp[i[1]][i[0]] = 1;
        }

    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] == dist[i][j]&&i!=j) {
                    dp[i][j] = (dp[i][j]+dp[i][k]*dp[k][j])%mod;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    string word ="abc";
    int ret = minTimeToType(word);
    return 0;
}