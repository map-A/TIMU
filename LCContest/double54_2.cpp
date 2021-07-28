#include "bits/stdc++.h"

using namespace std;
//https://blog.csdn.net/qq_41221520/article/details/108277801
int binarySearchFirstLessEqual(vector<long long> vec, int target) {
    int l = 0, r = vec.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] > target)  //关键点,>
        {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (r < 0)  //如果要找的是最后一个等于target的位置，则条件是 if(r<0 || vec[r]!=target)
        return -1;
    return r;
}

int chalkReplacer(vector<int> &chalk, int k) {
    int n = chalk.size();

    vector<long long> sum(n, 0);
    sum[0] = chalk[0];
    for (int i = 1; i < chalk.size(); i++) {
        sum[i] = sum[i - 1] + chalk[i];
    }
    long long r = binarySearchFirstLessEqual(sum, k);
    int ret = (r + 1 + n) % n;
    while (r == n - 1) {
        k %= sum[r];
        r = binarySearchFirstLessEqual(sum, k);
        ret = (r + 1 + n) % n;
        //cout<<r;
    }
    return ret;
}

int main() {
    vector<int> chalk = {3, 22, 9, 28, 48, 40, 47, 5, 19, 4, 9, 7, 11, 48};
    int k = 953;
    int ret = chalkReplacer(chalk, k);
    return 0;
}