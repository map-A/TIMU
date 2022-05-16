#include "bits/stdc++.h"

using namespace std;
vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    vector<int>ret(n);
    for(int i=0;i<n;i++){
        ret[i] = nums[nums[i]];
    }
    return ret;
}


int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int ret = 0;
    int n = dist.size();
    vector<double>time(n,0);
    for (int i = 0; i < n; ++i) {
        time[i] = 1.0*dist[i]/speed[i];
    }
    sort(time.begin(),time.end());
    for(int i=0;i<n;++i){
        if(ret>time[i]) return ret;
        ret++;
    }
    return ret;
}

long long fast(long long a, long b, long p) {
    long long a1 = a, t = 1;

    while (b > 0) {
        if (b & 1)
            t = (t % p) * (a1 % p) % p;
        a1 = (a1 % p) * (a1 % p) % p;

        b /= 2;
    }

    return (long long) (t % p);

}

int countGoodNumbers(long long n) {
    int ret;
    long long mod = 1e9 + 7;
    if (n % 2 == 0) {
        ret = (fast(4, n / 2, mod) * fast(5, n / 2, mod)) % mod;
    } else {
        ret = (fast(4, n / 2, mod) * fast(5, n / 2 + 1, mod)) % mod;
    }
    return ret;
}



int main() {


    return 0;
}