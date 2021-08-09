#include "bits/stdc++.h"

using namespace std;
vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> d, ans;
    for (int ob: obstacles) {
        // 这里需要改成 >=
        if (d.empty() || ob >= d.back()) {
            d.push_back(ob);
            ans.push_back(d.size());
        }
        else {
            // 将 300 题解中的二分查找改为 API 调用使得代码更加直观
            // 如果是最长严格递增子序列，这里是 lower_bound
            // 如果是最长递增子序列，这里是 upper_bound
            int loc = upper_bound(d.begin(), d.end(), ob) - d.begin();
            ans.push_back(loc + 1);
            d[loc] = ob;
        }
    }
    return ans;
}
int main() {

    return 0;
}