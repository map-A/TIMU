#include "bits/stdc++.h"

using namespace std;

bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    for (auto i:triplets) {
        if (i[0] == target[0] && i[1] == target[1] && i[2] == target[2]) return true;
    }
    //选取两个元素
    int n = triplets.size();
    vector<int>tmp = {0,0,0};
    for (int i = 0; i < n; i++) {
        if(triplets[i][0]==target[0]||triplets[i][1]==target[1]||triplets[i][2]==target[2]){
            if(triplets[i][0]>target[0]||triplets[i][1]>target[1]||triplets[i][2]>target[2]){
                continue;
            }
            tmp[0] = max(tmp[0],triplets[i][0]);
            tmp[1] = max(tmp[1],triplets[i][1]);
            tmp[2] = max(tmp[2],triplets[i][2]);
        }
        if (tmp[0] == target[0] && tmp[1] == target[1] && tmp[2] == target[2]) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> triplets = {{2, 5, 3},
                                    {1, 8, 7},
                                    {1, 7, 5}};
    vector<int> target = {2, 7, 5};
    bool ret = mergeTriplets(triplets, target);
    return 0;
}