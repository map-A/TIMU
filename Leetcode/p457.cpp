#include "bits/stdc++.h"

using namespace std;
bool circularArrayLoop(vector<int>& nums) {
    map<int,int>m;//index-val
    int len = nums.size();
    for(int i=0;i<len;i++){
        m.clear();
        int circle_len =0;
        int start = i;

        int sign = 0;
        while(1){
            if(circle_len>len) break;
            if(m.count(start)){
                if(circle_len-m[start]>1)
                    return true;
                else{
                    break;
                }
            }

            m[start] = circle_len;
            if(sign==0 &&nums[start]<0) sign = -1;
            else if(sign==0 &&nums[start]>0) sign = 1;
            else if(sign!=0 &&nums[start]<0&&sign==1) break ;
            else if(sign!=0 &&nums[start]>0&&sign==-1) break ;
            start =(start+nums[start]+len*1000)%len;
            circle_len++;
        }
    }
    return false;
}
int main() {
    vector<int> nums = {1,1};
    auto ret = circularArrayLoop(nums);
    return 0;
}