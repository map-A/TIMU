#include "bits/stdc++.h"

using namespace std;

int A[1001][1001];
int MaxSum[1001][1001];

int main() {
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    MaxSum[0][0] = A[0][0];
    for (int i = 1; i < N; i++)
        for (int j = 0; j <= i; j++) {
            MaxSum[i][j] = 0;
            if (j < i) {
                MaxSum[i][j] = MaxSum[i - 1][j];
            }
            if (j > 0 && MaxSum[i - 1][j - 1] > MaxSum[i][j]) {
                MaxSum[i][j] = MaxSum[i - 1][j - 1];
            }
            MaxSum[i][j] += A[i][j];
        }
    int ret = 0;
    for (int j = 0; j < N; j++) {
        if (MaxSum[N - 1][j] > ret) {
            ret = MaxSum[N - 1][j];
        }
    }

    printf("%d\n", ret);
}
