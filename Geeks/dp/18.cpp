#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

/*
 * 划分一个集合成为两个集合，他们的和相等
 * */
bool findPartiion(const int arr[], int n) {
    int sum = 0;
    int i, j;

    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1][n + 1];

    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;

    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
        }
    }

    return part[sum / 2][n];
}

int main() {
    int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (findPartiion(arr, n))
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";
    return 0;
}