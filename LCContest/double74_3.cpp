#include "bits/stdc++.h"

using namespace std;

int halveArray(vector<int>& nums) {
    double sum=0,num=0;
    priority_queue<double> a;
    // accumulate 需要考虑到int 的范围
    for(int i=0;i<nums.size();i++)a.push(nums[i]),sum+=nums[i];
    for(int i=1;i<=nums.size();i++)
    {
        double xx=a.top();a.pop();
        num+=xx/2.0;
        a.push(xx/2.0);
        if(num>=sum/2.0)return i;
    }
    return nums.size();
}
int main() {

    return 0;
}