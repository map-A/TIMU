#include "bits/stdc++.h"

using namespace std;
int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int ret = 0;
    for (int j = 0; j < n2; ++j){
        while (i < n1 && nums1[i] > nums2[j]){
            ++i;
        }
        if (i < n1){
            ret = max(ret, j - i);
        }
    }
    return ret;
}

int main() {

    return 0;
}