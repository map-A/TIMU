#include "bits/stdc++.h"

using namespace std;
int minimumSum(int num) {
    vector<int> digits;
    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }
    sort(digits.begin(), digits.end());
    return 10 * (digits[0] + digits[1]) + digits[2] + digits[3];
}


vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> ret(n, pivot);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < pivot) {
            ret[left++] = nums[i];
        }
        else if (nums[i] > pivot) {
            ret[right--] = nums[i];
        }
    }
    reverse(ret.begin() + right + 1, ret.end());
    return ret;
}


int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    vector<int>t(4);
    int k,l,ans=INT_MAX;
    for(int i=1;i<10000;i++)
    {
        t[0]=i/1000;
        t[1]=i/100%10;
        t[2]=i/10%10;
        t[3]=i%10;
        if(t[0]*600+t[1]*60+t[2]*10+t[3]!=targetSeconds)
            continue;
        int j;
        for(j=0;j<4&&!t[j];j++);

        for(l=0,k=startAt;j<4;j++)
        {
            if(k!=t[j])
            {
                k=t[j];
                l+=moveCost;
            }
            l+=pushCost;
        }
        ans=min(ans,l);
    }
    return ans;
}




int main() {

    return 0;
}