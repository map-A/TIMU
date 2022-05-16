#include "bits/stdc++.h"

using namespace std;
int countPairs(vector<int>& nums, int k) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if(nums[i]==nums[j]&&(i*j%k==0))
                ret++;
        }
    }
    return ret;
}


vector<long long> sumOfThree(long long num) {
    if(num%3==0){
        return {num/3-1,num/3,num/3+1};
    }
    return {};

}


vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2 != 0) {
        return {};
    }
    vector<long long> ret;
    long long cnt = 0;
    for (int i = 2; ; i += 2) {
        if (cnt + i > finalSum) {
            ret.back() += finalSum - cnt;
            break;
        }
        ret.push_back(i);
        cnt += i;
    }
    return ret;
}



int main() {

    return 0;
}