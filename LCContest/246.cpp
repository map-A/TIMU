#include "bits/stdc++.h"

using namespace std;
static bool cmp(string a,string b){
    if(a.size()>b.size()){
        return true;
    }
    else if(a.size()<b.size()){
        return false;
    }
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]) return true;
            else if(a[i]<b[i])  return false;
            else continue;
        }
    }
    return true;
}

string largestOddNumber(string num) {
    string ret = "";
    int n = num.size();
    vector<int>index;
    for(int i=0;i<n;i++){
        if((num[i]-'0')%2==1){
            index.push_back(i);
        }
    }
    for(int i=n;i>0;i--){
        //判断长度为i的
        for(int j=0;j<n-i+1;j++){
            string tmp=num.substr(j,i);

            if(tmp[0]!=0&&(tmp[i-1]-'0')%2==1&&!cmp(ret,tmp)){
                ret = tmp;
            }
        }
        if(ret!="") return ret;
    }
    return ret;

}




int numberOfRounds(string startTime, string finishTime) {
    int start_hour = stoi(startTime.substr(0, 2));
    int start_min = stoi(startTime.substr(3, 2));
    int end_hour = stoi(finishTime.substr(0, 2));
    int end_min = stoi(finishTime.substr(3, 2));

    int s_t = start_hour*60+start_min;
    int e_t = end_hour*60+end_min;
    if(e_t<s_t)e_t+=24*60;
    int cnt = 0;
    for(int i=s_t/15*15;i<e_t;i+=15){
        if(s_t<=i&&i<=e_t&&s_t<i+15&&i+15<=b){
            cnt++;
        }
    }
    return cnt;
}

vector<vector<int>> dirs = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

void BFS(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, bool &flag) {
    int m = grid2.size(), n = grid2[0].size();
    queue<vector<int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            for (auto dir:dirs) {
                int x = q.front()[0] + dir[0];
                int y = q.front()[1] + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1) {
                    q.push({x, y});
                    grid2[x][y] = 0;

                }
            }
            if (grid1[q.front()[0]][q.front()[1]] == 0 && flag == true) {
                flag = false;
            }
            q.pop();
        }
    }
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    if (grid2.size() == 0) return 0;
    int m = grid2.size(), n = grid2[0].size();
    //vector<vector<int>>visit(m,vector<int>(n,0));
    int ret = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                bool flag = true;
                grid2[i][j]=0;
                BFS(grid1, grid2, i, j, flag);
                if (flag == true)
                    ret++;
            }
        }
    }
    return ret;

}


vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<vector<int>> pre(n+1, vector<int>(101, 0));
    pre[1][nums[0]]++;
    for(int i=2;i<n+1;i++){
        pre[i] = pre[i-1];
        pre[i][nums[i-1]]++;
    }

    int m = queries.size();
    vector<int> ret(m, 0);
    for (int i = 0; i < m; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        //找l和r之间的最小值
        int minVal = INT_MAX;
        int minnum = 0;//用来做差值的
        for (int j = 1; j < 101; j++) {
            if (pre[l][j] != pre[r+1][j]) {
                if (minnum != 0) {
                    minVal = min(minVal, j - minnum);
                }
                minnum = j;
            }

        }
        if (minVal == INT_MAX) {
            minVal = -1;
        }
        ret[i] = minVal;
    }
    return ret;
}

int main() {
    string num = "4205";
    auto ret = largestOddNumber(num);
    return 0;
}