#include "bits/stdc++.h"

using namespace std;
int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;
    for(auto &i:operations){
        if(i=="--X"||i=="X--"){
            x--;
        }
        else{
            x++;
        }
    }
    return x;
}

int sumOfBeauties(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    vector<int>pre(n,0),suff(n,0);
    pre[0] = nums[0];
    suff[n-1] = nums[n-1];
    for(int i=1;i<n;i++){
        pre[i] = max(pre[i-1],nums[i]);
        suff[n-i-1] = min(suff[n-i],nums[n-1-i]);
    }
    for(int i=1;i+1<n;i++){
        if(nums[i]>pre[i-1]&&nums[i]<suff[i+1]){
            ret+=2;
        }
        else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1]){
            ret++;
        }
    }
    return ret;
}

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