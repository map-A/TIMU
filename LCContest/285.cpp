#include "bits/stdc++.h"

using namespace std;
int countHillValley(vector<int>& nums) {
    vector<int> v;
    for (int x : nums)
        //去重
        if (v.empty() or v.back() != x) v.push_back(x);
    int res = 0;
    for (int i = 1; i + 1 < v.size(); i += 1) {
        res += (v[i] - v[i - 1]) * (v[i] - v[i + 1]) > 0;
    }
    return res;
}

int countCollisions(string directions) {
    int ans = 0, x = 0, y = 0;
    for (char c : directions) {
        if (c == 'L') ans += x;
        else x = 1;
    }

    for (auto c=directions.rbegin();c!=directions.rend();c++) {
        if (*c == 'R') ans += y;
        else y = 1;
    }
    return ans;
}
vector<int> maximumBobPoints(int n, vector<int>& a) {
    vector<int> ans(12);
    int x = -1;
    for (int i = 0; i < (1 << 12); ++i) {
        int sum = 0, sumx = 0;
        for (int j = 0; j < 12; ++j) {
            if ((i >> j) & 1) {
                //若i的第j位为1
                sum += a[j] + 1; //剑
                sumx += j;// 得分
            }
        }
        if (sum > n) {
            continue;
        }
        if (sumx > x) {
            x = sumx;
            for (int j = 0; j <12; ++j) {
                if ((i >> j) & 1) {
                    ans[j] = a[j] + 1;
                } else {
                    ans[j] = 0;
                }
            }
            ans[0] += n - sum;
        }
    }
    return ans;
}

int main() {
    vector<int>nums = {2,4,1,1,6,5};
    int ret = countHillValley(nums);
    return 0;
}