#include "bits/stdc++.h"

using namespace std;
typedef long long LL;
int binarySearchFirstLess(vector<int> vec,int left,int right, int target)
{
    int l = left, r = right;
    while (l <= r)
    {
        int mid=l+(r-l)/2;
        if (vec[mid] >= target)  //关键点，>=
        {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if(r<0)     //区分索引越界，即没找到
        return -1;
    return r;
}

int binarySearchFirstGreater(vector<int> vec,int left,int right, int target)
{
    int l = left, r = right;
    while (l <= r)
    {
        int mid=l+(r-l)/2;
        if (vec[mid] <= target)  //关键点,<=
        {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (l >= vec.size())      //区分索引越界，即没找到
        return -1;
    return l;
}

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int left = j + 1, right = n - 1, k = j;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] < nums[i] + nums[j]) {
                    k = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            ans += k - j;
        }
    }
    return ans;
}

int main() {
    vector<int>nums = {2};
   int ret =  triangleNumber(nums);
    return 0;
}
