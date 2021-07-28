#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

/*
 * 最大和递增子序列
 * */
int maxSumIS(int arr[], int n) {
    int i, j, max = 0;
    int msis[n];

    /* Initialize msis values
    for all indexes */
    for (i = 0; i < n; i++)
        msis[i] = arr[i];

    /* Compute maximum sum values
    in bottom up manner */
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] &&
                msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    /* Pick maximum of
    all msis values */
    for (i = 0; i < n; i++)
        if (max < msis[i])
            max = msis[i];
    return max;
}

int main() {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ret = maxSumIS(arr,n);
    return 0;
}
