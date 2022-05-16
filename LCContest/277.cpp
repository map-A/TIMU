#include "bits/stdc++.h"

using namespace std;
int countElements(vector<int>& nums) {
    int smallest = *min_element(nums.begin(), nums.end());
    int largest = *max_element(nums.begin(), nums.end());
    int res = 0;
    for (int num: nums) {
        if (smallest < num && num < largest) {
            ++res;
        }
    }
    return res;
}

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;
    vector<int> ret(n);
    for (int num : nums) {
        if (num > 0) {
            ret[i] = num;
            i += 2;
        } else {
            ret[j] = num;
            j += 2;
        }
    }
    return ret;
}

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