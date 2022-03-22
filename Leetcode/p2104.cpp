#include "bits/stdc++.h"

using namespace std;
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int j = i; j < n; j++) {
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
            ret += maxVal - minVal;
        }
    }
    return ret;
}
#include <stdio.h>
#include <cstdlib>
int MyCompare(const void *elem1, const void* elem2){
    unsigned int * p1, *p2;
    p1 =  (unsigned int *)elem1;
    p2 =  (unsigned int *)elem2;
    return(*p1% 10)- (*p2 %10);

}
#define  NUM 5

int main() {
    unsigned  int an[NUM]  = {8,123,11,10,4};
    qsort(an, NUM, sizeof(unsigned  int), MyCompare);
    for (int i = 0; i < NUM; ++i) {
        printf("%d",an[i]);
    }
    return 0;
}