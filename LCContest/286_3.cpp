#include "bits/stdc++.h"

using namespace std;
vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    vector<long long> res;
    int n = intLength / 2;
    int m = intLength % 2;

    long long p = 1;
    for (int i = 0; i < n + m; ++i) p *= 10;
    long long q = p / 10;

    for (auto k : queries)
    {
        long long tmp = q + k - 1;
        if (q <= tmp && tmp < p)
        {
            string s = to_string(tmp);
            for (int i = 0; i < n; ++i)
                s += s[n - i - 1];
            long long val = stoll(s);
            res.push_back(val);
        }
        else
        {
            res.push_back(-1);
        }
    }
    return res;
}
int main() {

    return 0;
}