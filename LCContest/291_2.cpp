#include "bits/stdc++.h"

using namespace std;
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
int main() {
    vector<int>ret = {3,4,2,3,4,7};
    int t = minimumCardPickup(ret);
    return 0;
}