#include "bits/stdc++.h"

using namespace std;
long long solve(int* A, int ALen) {
    sort(A, A + ALen);
    long long nums1 = (long long)A[0] * A[1] * A[ALen - 1];
    long long nums2 = (long long)A[ALen - 3] * A[ALen - 2] * A[ALen - 1];
    return max(nums1, nums2);
}


long long solve2(int* A, int ALen) {
    // 最小的和第二小的
    int min1 = INT_MAX, min2 = INT_MAX;
    // 最大的、第二大的和第三大的
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    // 顺序遍历查找最小的两个数、最大的三个数
    for(int i = 0;i < ALen;i ++){
        if(A[i] < min1){//更新最小值
            min2 = min1;
            min1 = A[i];
        }else if(A[i] < min2){//更新第二小
            min2 = A[i];
        }
        if (A[i] > max1){//更新最大值
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }else if(A[i] > max2){//更新第二大
            max3 = max2;
            max2 = A[i];
        }else if(A[i] > max3){//更新第三大
            max3 = A[i];
        }
    }
    return max((long long)min1 * min2 * max1,(long long) max1 * max2 * max3);
}
int main() {

    return 0;
}