#include "bits/stdc++.h"

using namespace std;
vector<int> intersection(vector<vector<int>>& nums) {
    vector<int>bucket(1001,0);
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
            bucket[nums[i][j]]++;
        }
    }
    vector<int>ret;
    for (int i = 0; i < bucket.size(); ++i) {
        if(bucket[i]>=(int)nums.size()){
            ret.push_back(i);
        }
    }
    return ret;
}

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

vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
    vector<vector<int>> vp(101);
    for (auto &v: rectangles) {
        //遍历所有矩形
        int l = v[0], h = v[1];
        //l为x，h为y
        for (int j = 0; j <= h; j += 1)
            //右边的线上所有点计入
            vp[j].push_back(l);
    }
    for (int i = 0; i <= 100; i += 1){
        sort(vp[i].begin(), vp[i].end());

    }
    vector<int> res;
    for (auto &v: points) {
        int x = v[0], y = v[1];
        res.push_back(vp[y].size() - (lower_bound(vp[y].begin(), vp[y].end(), x) - vp[y].begin()));
    }
    return res;

}
int main() {

    return 0;
}