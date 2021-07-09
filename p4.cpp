#include "bits/stdc++.h"

using namespace std;

vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
    int i = 0, j = 0;
    int m = nums1.size(), n = nums2.size();
    vector<int> ret;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            ret.push_back(nums1[i]);
            i++;
        } else {
            ret.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m) {
        ret.push_back(nums1[i]);
        i++;
    }
    while (j < n) {
        ret.push_back(nums2[j]);
        j++;
    }
    return ret;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ret = merge(nums1, nums2);
    if (ret.size() % 2 == 0) return (ret[ret.size() / 2 - 1] + ret[ret.size() / 2]) / 2.0;
    else return ret[ret.size() / 2] * 1.0;

}


int findMedianinTwoSortedAray(vector<int> &arr1, vector<int> &arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int len = m + n;
    int left = -1, right = -1;
    int aStart = 0, bStart = 0;
    for (int i = 0; i <= len / 2; i++) {
        left = right;
        if (aStart < m && (bStart >= n || arr1[aStart] < arr2[bStart])) {
            right = arr1[aStart++];
        } else {
            right = arr2[bStart++];
        }
    }
    return left;
}

int main() {
    return 0;
}