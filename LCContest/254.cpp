#include "bits/stdc++.h"
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
    int ret = 0;
    for(auto i:patterns){
        if(word.find(i)!=word.npos){
            ret++;
        }
    }
    return ret;
}


vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> ret(nums.size());
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1, i = 0;
    while (l <= r){
        if (i % 2 == 0) ret[i++] = nums[l++];
        else ret[i++] = nums[r--];
    }
    return ret;
}


int mod = 1e9+7;

int minNonZeroProduct(int p)
{
    long long ret = ((1LL << p) - 1) % mod , k = (1LL << p - 1) - 1;
    for(long long multi = ((1LL << p) - 2) % mod ; k ; k >>= 1)
    {
        if(k & 1) ret = ret * multi % mod;
        multi = multi * multi % mod;
    }
    return ret;
}
int main() {

    return 0;
}