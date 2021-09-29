#include "bits/stdc++.h"

using namespace std;
class DetectSquares {
public:
    map<vector<int>,int>m;
    DetectSquares() {
    }

    void add(vector<int> point) {
        m[point]++;
    }

    int count(vector<int> point) {
        int ret = 0;
        int x = point[0],y = point[1];
        for(auto &i:m){
            int x1 = i.first[0],y1 = i.first[1],t = i.second;
            if(x1==x||y1==y) continue;
            if(abs(x1-x)==abs(y1-y)){
                ret+=t* m[{x1,y}]*m[{x,y1}];
            }
        }
        return ret;
    }
};
int main() {

    return 0;
}