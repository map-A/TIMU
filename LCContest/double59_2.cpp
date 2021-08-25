#include "bits/stdc++.h"

using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    long long ret = 0;
    vector<int> minus(m, INT_MAX);
    int minus_count = 0;
    for (int i = 0; i < m; i++) {
        //找到每一行里面的负数个数
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                minus_count++;
            }
            ret += abs(matrix[i][j]);
            minus[i] = min(abs(matrix[i][j]), minus[i]);

        }
    }
    int t = *min_element(minus.begin(), minus.end());
    if (minus_count % 2 == 0) {
        return ret;
    } else {
        return ret - 2 * (t);
    }
}

int main() {

    return 0;
}