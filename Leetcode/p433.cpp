#include "bits/stdc++.h"

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> cnt;
    unordered_set<string> visited;
    char keys[4] = {'A', 'C', 'G', 'T'};
    for (auto & w : bank) {
        cnt.emplace(w);
    }
    if (start == end) {
        return 0;
    }
    if (!cnt.count(end)) {
        return -1;
    }
    queue<string> qu;
    qu.emplace(start);
    visited.emplace(start);
    int step = 1;
    while (!qu.empty()) {
        int sz = qu.size();
        for (int i = 0; i < sz; i++) {
            string curr = qu.front();
            qu.pop();
            for (int j = 0; j < 8; j++) { // 遍历基因的每一个位置
                for (int k = 0; k < 4; k++) { // 尝试替换其中一个位置的基因
                    if (keys[k] != curr[j]) {
                        string next = curr;
                        next[j] = keys[k];
                        if (!visited.count(next) && cnt.count(next)) {
                            if (next == end) {
                                return step;
                            }
                            qu.emplace(next);
                            visited.emplace(next);
                        }
                    }
                }
            }
        }
        step++;
    }
    return -1;
}
int main() {

    return 0;
}