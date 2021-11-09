#include "bits/stdc++.h"

using namespace std;
vector<int> analysisHistogram(vector<int>& heights, int cnt) {
    sort(heights.begin(),heights.end());
    vector<int>ret;
    int tmp = INT_MAX;
    for(int i=0;i<heights.size()-cnt+1;i++){
        if(heights[i+cnt-1]-heights[i]<tmp){
            tmp = heights[i+cnt-1]-heights[i];
            ret.assign(heights.begin()+i,heights.begin()+i+cnt);
        }
    }
    return ret;
}
int main() {

    vector<int>heights = {2,0,4,7,7,4,7,1,6,5};
    int cnt = 5;
    auto ret = analysisHistogram(heights,cnt);

    return 0;
}