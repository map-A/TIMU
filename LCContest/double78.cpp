#include "bits/stdc++.h"

using namespace std;
int divisorSubstrings(int num, int k) {
    int ret = 0;
    string str = to_string(num);
    for (int i = 0; i <=str.size()-k; ++i) {
        string s = str.substr(i,k);
        int tmp = stoi(s);
        if(tmp!=0&&num% tmp==0){
            ret++;
        }
    }
    return ret;
}

int waysToSplitArray(vector<int>& nums) {
    long long sum = std::accumulate(nums.begin(), nums.end(), (long long)0);
    long long left = 0;
    int ret = 0;
    for (int i = 0; i <nums.size()-1 ; ++i) {
        left+=nums[i];
        sum-=nums[i];
        if(left>=sum)ret++;
    }
    return ret;
}
int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {

}


int main() {

    return 0;
}