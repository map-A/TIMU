#include "bits/stdc++.h"

using namespace std;
vector<int> findLonely(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int it : nums) {
        ++mp[it];
    }
    vector<int> res;
    for (auto it : mp) {
        if (it.second != 1) {
            continue;
        }
        if (!mp.count(it.first + 1) && !mp.count(it.first - 1)) {
            res.emplace_back(it.first);
        }
    }
    return res;
}
int main() {

    return 0;
}