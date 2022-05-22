#include "bits/stdc++.h"

using namespace std;
int divisorSubstrings(int num, int k) {
    int ret = 0;
    string str = to_string(num);
    for (int i = 0; i <=str.size()-k; ++i) {
        string s = str.substr(i,k);
        int tmp = stoi(s);
        if(tmp!=0&&num% tmp==0){
            ret++;
        }
    }
    return ret;
}

int waysToSplitArray(vector<int>& nums) {
    long long sum = std::accumulate(nums.begin(), nums.end(), (long long)0);
    long long left = 0;
    int ret = 0;
    for (int i = 0; i <nums.size()-1 ; ++i) {
        left+=nums[i];
        sum-=nums[i];
        if(left>=sum)ret++;
    }
    return ret;
}



int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());
    int ans = 0, l = 0, r = 0, sum = 0;
    while(r < tiles.size())
    {
        int leftbound = tiles[l][0], rightbound = leftbound + carpetLen - 1;
        if(rightbound >= tiles[r][1])  // 注意这里必须要有等于,否则会出现数组越界错误!
        {
            sum += tiles[r][1] - tiles[r][0] + 1;
            r++;
            ans = max(ans, sum);
        }
        else
        {
            if(rightbound >= tiles[r][0])
            {
                ans = max(ans, sum + rightbound - tiles[r][0] + 1);
            }
            sum -= tiles[l][1] - tiles[l][0] + 1;
            l++;
        }
    }
    return ans;
}


int main() {

    return 0;
}