#include "bits/stdc++.h"

using namespace std;
int mostFrequent(vector<int>& nums, int key) {
    vector<int>ret(1001,0);
    for(int i = 0; i < nums.size() - 1; i++) {
        if(nums[i] == key) {
            ret[nums[i + 1]]++;
        }
    }

    return max_element(ret.begin(),ret.end())-ret.begin();
}



vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int,int>>t(nums.size());
    for (int i = 0; i <nums.size() ; ++i) {
        string new_string = to_string(nums[i]);
        for (int i = 0; i < new_string.size(); ++i) {
            new_string[i] = '0'+(mapping[new_string[i]-'0']);
        }
        t[i] = {stoi(new_string), i};
    }
    sort(t.begin(),t.end());
    vector<int>ret(nums.size());
    for(int i = 0;i<nums.size();i++){
        ret[i] = nums[t[i].second];
    }
    return ret;
}


void bfs(int S, vector<vector<int>> &my_e, vector<vector<int>> &ret) {
    vector<bool> vis(my_e.size(), false);
    queue<int> q;
    q.push(S);
    vis[S] = true;
    while (!q.empty()) {
        int sn = q.front();
        q.pop();
        for (int fn: my_e[sn])
            if (!vis[fn]) {
                vis[fn] = true;
                q.push(fn);
                ret[fn].push_back(S);
            }
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> ret = vector<vector<int>>(n);
    vector<vector<int>> my_e = vector<vector<int>>(n);
    vector<bool> vis(n, false);

    for (auto &edge: edges) {
        my_e[edge[0]].push_back(edge[1]);
    }
    for (int i = 0; i < n; i++) {
        bfs(i, my_e, ret);
    }
    return ret;
}



int minMovesToMakePalindrome(string s) {
    if (s.size() == 0) return 0;
    int cnt = 0, n = s.size();
    string temp;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == s[0] && i != 0) {
            for (int j = 1; j < i; j++) temp += s[j];
            for (int j = i + 1; j < n; j++) temp += s[j];
            cnt += n - i - 1;
            break;
        }
        if (i == 0) {
            cnt += n / 2;
            temp = s.substr(1);
        }
    }
    return cnt + minMovesToMakePalindrome(temp);

}


int main() {
    vector<int>nums = {1,100,200,1,100};
    int key = 1;
    int ret = mostFrequent(nums,key);
    return 0;
}