#include "bits/stdc++.h"

using namespace std;
string removeDigit(string number, char digit) {
    string ans, best;
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] == digit) {
            best = number.substr(0, i) + number.substr(i + 1);
            if (i < number.size() - 1 and number[i + 1] > digit)
                return best;
            else
                ans = best;
        }
    }
    return ans;
}


int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> indices;
    int minPickup = INT_MAX;

    for (int i = 0; i < cards.size(); ++i) {
        int card = cards[i];

        if (indices.count(card) != 0) {
            minPickup = min(minPickup, i - indices[card] + 1);
        }

        indices[card] = i;
    }

    return minPickup == INT_MAX ? -1 : minPickup;
}


int countDistinct(vector<int>& nums, int k, int p) {
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        vector<int> t;
        /* 区间[i,j], 满足最多k个可整除元素, 加入set中 */
        for (int j = i; j < n; j++) {
            t.push_back(nums[j]);
            if (nums[j] % p == 0) {
                cnt++;
            }
            if (cnt <= k) { /* 可整除的元素个数不大于k */
                st.insert(t);
            } else {
                break;
            }
        }
    }
    return st.size();
}
int main() {

    return 0;
}