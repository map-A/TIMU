#include "bits/stdc++.h"
using namespace std;
vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int>ret;
    for(auto i:queries){
        int count = 0;
        for(auto j : points){
            if(pow(j[0]-i[0],2)+pow(j[1]-i[1],2)<=pow(i[2],2)){
                count++;
            }
        }
        ret.push_back(count);
    }
    return ret;
}
int main() {
    vector<vector<int>>points = {{1,3},{3,3},{5,3},{2,2}};
    vector<vector<int>>querys = {{2,3,1},{4,3,1},{1,1,2}};
    vector<int>ret = countPoints(points,querys);
    for(auto i:ret){
        cout<<i;
    }
    return 0;
}