#include "bits/stdc++.h"

using namespace std;

int search(vector<int> &nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = (right - left) / 2 + left;
        if (nums[mid] == target) {
            break;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    //向左试探第一个出现的位置
    int ret = mid;
    while (mid > 0 && nums[mid] == target) {
        mid--;
        if (nums[mid] == target) {
            ret = mid;
        }
    }
    return nums[ret] == target ? ret : -1;
}

int main() {

    return 0;
}