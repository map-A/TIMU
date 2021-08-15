#include "bits/stdc++.h"

using namespace std;
void solve(string s){
    while(s.find("ab")!=s.npos){
        s.replace(s.find("ab"),2,"");
    }
    if(s=="")cout<<"YES";
    else cout<<"NO";
}

void solve2(vector<int>&nums){
    set<int>s1;
    set<int>s2;
    for(int i=0;i<nums.size();i+=2){
        s1.insert(nums[i]);
        s2.insert(nums[i+1]);
    }
    cout<<s1.size()+s2.size()-2;
}

vector<vector<int>> dirs = {{1,  0},
                            {-1, 0},
                            {0,  1},
                            {0,  -1}};

bool canaccess(int x1, int y1,int x2,int y2){
    if(x2-1==x1&&y2-1==y1) return true;
    if(x2-1==x1&&y2+1==y1) return true;
    if(x2+1==x1&&y2-1==y1) return true;
    if(x2+1==x1&&y2+1==y1) return true;
    if(x2-1==x1&&y2==y1) return true;
    if(x2+1==x1&&y2==y1) return true;
    if(y2+1==y1&&x2==x1) return true;
    if(y2-1==y1&&x2==x1) return true;
    return false;
}

int BFS(vector<vector<char>> &grid, int x1, int y1,int x2,int y2) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    int count = 0;
    int ret = INT_MAX;
    queue<vector<int>> q;
    q.push({x1, x2});
    while (!q.empty()) {
        int len = q.size();
        count++;
        for (int k = 0; k < len; ++k) {
            for (auto dir:dirs) {
                int x = q.front()[0] + dir[0];
                int y = q.front()[1] + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && vis[x][y] == 0&&grid[x][y]=='.') {
                    if(canaccess(x,y,x2,y2)){
                        int tmp =  (x1^x2)^count^(y1^y2);
                        ret  = min(tmp,ret);
                    }
                    q.push({x, y});
                    vis[x][y] = 1;
                }
            }
            q.pop();
        }
    }
    return ret;
}





int main() {
    int T;
    cin>>T;
    while(T--){
        int m,n;
        scanf("%d %d",&m,&n);
        vector<vector<char>>grid(m);
        for(int i=0;i<m;i++){
            string line;
            getline(cin,line);
            string tmp;
            stringstream ss(line);
            while(getline(ss, tmp, ' ')){
                grid[i].push_back(tmp[0]);
            }
        }
    }
    return 0;
}




class Solution {
private:
    int dirs[8][2] = { {0,1}, {0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
public:

    bool isNeibor(pair<int, int>& p, const int& row, const int& col, const vector<vector<char>>& grid, const int& x2, const int& y2) {
        for (int i = 0; i < 8; i++) {
            int x = p.first + dirs[i][0], y = p.second + dirs[i][1];
            if (x >= row || x < 0 || y >= col || y < 0 || grid[x][y] == '#') continue;
            if (x == x2 && y == y2) return true;
        }
        return false;
    }

    int func(vector<vector<char>>& grid, int x1, int y1, int x2, int y2) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        q.push({ x1,y1 });
        visited[x1][y1] = true;
        int t = 0;
        int tmp;
        int ret  = INT_MAX;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                visited[cur.first][cur.second] = true;
                q.pop();
                if (isNeibor(cur, row, col, grid, x2, y2)) {
                    tmp = ((x1 * x2) ^ t) ^ (y1 * y2);
                    ret  = min(ret,tmp);
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        int x = cur.first + dirs[i][0], y = cur.second + dirs[i][1];
                        if (x >= row || x < 0 || y >= col || y < 0 || grid[x][y] == '#' || visited[x][y] == true) continue;
                        else q.push({ x,y });
                    }
                }
            }
            t++;
        }
        return ret;
    }
};