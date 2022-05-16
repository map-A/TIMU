#include "bits/stdc++.h"

using namespace std;

bool no_repeat(string s) {
    int vis[26];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < s.size(); i++) {
        if (vis[s[i] - 'a'] == 0) {
            vis[s[i] - 'a'] = 1;
        } else return false;
    }
    return true;
}

int countGoodSubstrings(string s) {
    int count = 0;
    if(s.size()<3){
        return count;
    }
    for (int i = 0; i < s.size() - 2; i++) {
        if (no_repeat(s.substr(i, 3))) {
            count++;
        }
    }
    return count;
}


int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ret = INT_MIN;
    int tmp = INT_MIN;
    for (auto i = 0; i < nums.size() / 2; i++) {
        tmp = max(tmp, nums[i] + nums[nums.size() - i - 1]);
        ret = max(ret, tmp);
    }
    return ret;
}

vector<int> putNum(vector<int> &a, int num) {
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        //先找一遍有没有重复元素
        if (a[i] == num) {
            return a;
        }
    }
    if (a[0] < num) {
        a[0] = num;
        return a;
    }
    return a;
}

vector<int> getBiggestThree(vector<vector<int>> &grid) {
    vector<int> ret(3, 0);
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //以ij为中心，长度
            int len = min({i, j, m - 1 - i, n - 1 - j});
            for (int k = 0; k <= len; k++) {
                //求长度为k，以ij为中心元素和
                int sum = 0;
                if (k == 0) {
                    sum = grid[i][j];
                } else {
                    //加上棱形线上面的元素
                    for(int x=i,y=j-k;x<i+k&&y<j;x++,y++){
                        sum+=grid[x][y];
                    }
                    for(int x = i+k,y=j;x>i&&y<j+k;x--,y++){
                        sum+=grid[x][y];
                    }
                    for(int x=i,y=j+k;x>i-k&&y>j;x--,y--){
                        sum+=grid[x][y];
                    }
                    for(int x=i-k,y=j;x<i&&y>j-k;x++,y--){
                        sum+=grid[x][y];
                    }

                }
                putNum(ret, sum);
            }
        }
    }
    sort(ret.begin(), ret.end(), greater<int>());
    vector<int> finalret;
    for (auto i:ret) {
        if (i != 0) {
            finalret.push_back(i);
        }
    }
    return finalret;
}

int main() {
    string s = "xyzzaz";
    int ret = countGoodSubstrings(s);
    return 0;
}