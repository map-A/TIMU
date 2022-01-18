#include "bits/stdc++.h"

using namespace std;
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    vector<int>diff(n);
    for (int i = 1; i < n; ++i) {
        if(heights[i]-heights[i-1]>0)
            diff[i] = heights[i]-heights[i-1];
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    int i= 0;
    for ( i; i < n;) {
        if(diff[i]>0){
            if(ladders>0){
                ladders--;
                pq.push(diff[i]);
                i++;
            }
            else if(ladders==0){
                if(!pq.empty()){
                    if(pq.top()<diff[i]){
                        bricks-=pq.top();
                        pq.pop();
                        pq.push(diff[i]);
                    }
                    else{
                        bricks-=diff[i];
                    }
                    if(bricks<0) return i-1;
                    i++;
                }
                else{
                    if(bricks>=diff[i]){
                        bricks-=diff[i];
                    }
                    else{
                        return i-1;
                    }
                }
            }
        }
        else{
            i++;
        }
    }
    return i;
}
int main() {
    vector<int>height = {14,3,19,3};
    int bricks = 17,ladders = 0;
    int ret = furthestBuilding(height,bricks,ladders);
    return 0;
}