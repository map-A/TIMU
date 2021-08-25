#include "bits/stdc++.h"

using namespace std;
bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int t = abs(target[0]-0)+abs(target[1]-0);
    vector<int>times;
    for(int i=0;i<ghosts.size();i++){
        times.push_back(abs(target[0]-ghosts[i][0])+abs(target[1]-ghosts[i][1]));
    }
    return *min_element(times.begin(),times.end())>t?true:false;
}
int main() {

    return 0;
}