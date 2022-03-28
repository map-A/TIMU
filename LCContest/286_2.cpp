#include "bits/stdc++.h"

using namespace std;
int minDeletion(vector<int>& nums) {
    int res= 0;
    for(int i =0 ;i<nums.size();i++){
        if((i-res)%2 == 0){
            if(i<nums.size()-1&&nums[i]==nums[i+1]){
                res++;
            }
        }
    }
    if((nums.size()-res)%2==1) res++;
    return res;
}
int main() {

    return 0;
}