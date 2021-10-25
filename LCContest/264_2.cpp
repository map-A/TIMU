#include "bits/stdc++.h"

using namespace std;
    bool isBalance(int nums) {
        int hash[8] = {0};

        string tmp = to_string(nums);
        if(tmp.size()>7){
            return false;
        }
        for(auto i:tmp){
            if(i-'0'>=0&&i-'0'<8)
                hash[i-'0']++;
            else{
                return false;
            }
        }
        for (int i = 0; i <= 7; ++i) {
            if (hash[i] && hash[i] != i)   return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        if (n == 0) return 1;
        int i = n+1;
        for (; i < INT_MAX; ++i) {
            if (isBalance(i))   break;
        }
        return i;
    }
int main() {
    int n = 1227;
    auto ret = nextBeautifulNumber(n);
    return 0;
}