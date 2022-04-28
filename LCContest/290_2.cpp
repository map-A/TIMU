#include "bits/stdc++.h"

using namespace std;
int countLatticePoints(vector<vector<int>>& circles) {
    set<pair<int,int>>ret;
    for (int i = 0; i < circles.size(); ++i) {
        for (int x = circles[i][0]-circles[i][2]; x <= circles[i][0]+circles[i][2]; ++x) {
            for (int y= circles[i][1]-circles[i][2]; y <= circles[i][1]+circles[i][2]; ++y) {
                if((x-circles[i][0])*(x-circles[i][0])+(y-circles[i][1])*(y-circles[i][1])<=circles[i][2]*circles[i][2]){
                    ret.insert({x,y});
                }
            }
        }

    }
    return (int)ret.size();
}
int main() {

    return 0;
}