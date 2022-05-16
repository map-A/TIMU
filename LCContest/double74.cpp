#include "bits/stdc++.h"

using namespace std;
bool divideArray(vector<int>& nums) {
    vector<int>bz(1002,0);
    for (int i  = 0; i < nums.size(); i ++) bz[nums[i]] ++;
    for (int i  = 0; i < nums.size(); i ++) if (bz[nums[i]] & 1) return false;
    return true;
}


long long maximumSubsequenceCount(string text, string pattern) {
    long long sum=0;
    long long a=0;
    long long b=0;
    int len=text.size();
    if(pattern[0]==pattern[1])
    {
        for(int i=0;i<len;i++)
        {
            if(text[i]==pattern[0]) a++;
        }
        return (1+a)*a/2;
    }
    for(int i=0;i<len;i++)
    {
        if(text[i]==pattern[0])
        {
            a++;
        }
        else if(text[i]==pattern[1])
        {
            b++;
            sum=sum+a;//在pattern[1]之前有多少个a
        }
    }
    return sum+max(a,b);
}

int halveArray(vector<int>& nums) {
    double sum=0,num=0;
    priority_queue<double> a;
    // accumulate 需要考虑到int 的范围
    for(int i=0;i<nums.size();i++)a.push(nums[i]),sum+=nums[i];
    for(int i=1;i<=nums.size();i++)
    {
        double xx=a.top();a.pop();
        num+=xx/2.0;
        a.push(xx/2.0);
        if(num>=sum/2.0)return i;
    }
    return nums.size();
}


long long dp[1005][1005];
/* dp[i][j] 表示使用了i条地毯覆盖[0,j]的地板, 最小的白色砖块数 */
/* dp[0][j], [0,j]一共的白色砖块数 */
/* dp[i][j], dp[i][j] = min(dp[i][j-1] + floor[j], dp[i-1][j-carpetLen]) */
int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
    int n = floor.size();
    vector<vector<int>> dp(numCarpets + 1, vector<int>(n));
    int cnt = 0;
    /* dp初始化 */
    for (int j = 0; j < n; j++) {
        cnt += (floor[j] - '0');
        dp[0][j] = cnt;
    }
    /* dp动态方程转移 */
    for (int i = 1; i <= numCarpets; i++) {
        for (int j = 0; j < n; j++) {
            if (j < carpetLen) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min(dp[i][j - 1] + (floor[j] - '0'),
                               dp[i - 1][j - carpetLen]);
            }
        }
    }
    return dp[numCarpets][n - 1];
}



int main() {

    return 0;
}