#include "bits/stdc++.h"

using namespace std;
int countGoodRectangles(vector<vector<int>>& rectangles) {
    vector<int>v;
    for(auto i:rectangles){
        v.push_back(min(i[0],i[1]));
    }
    sort(v.begin(),v.end());
    int ret = 0;
    for(auto i=v.rbegin();i!=v.rend();i++){
        if(*i!=v.back()) {
            return ret;
        }
        ret++;
    }
    return ret;
}
int main() {
    vector<vector<int>>re = {{2,3},{3,7},{4,3},{3,7}};
    auto ret = countGoodRectangles(re);
    return 0;
}