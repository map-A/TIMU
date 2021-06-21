#include "bits/stdc++.h"

using namespace std;

int MoreThanHalfNum_Solution1(vector<int> numbers) {
    map<int, int> table;
    for (auto num:numbers) {
        table[num]++;
    }
    for (auto i:table) {
        if (i.second > numbers.size() / 2) {
            return i.first;
        }
    }
    return 0;
}

int MoreThanHalfNum_Solution2(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() / 2];
}

int count_in_range(vector<int> &numbers, int l, int r, int target) {
    int count = 0;
    for (int i = l; i <= r; ++i)
        if (numbers[i] == target)
            ++count;
    return count;
}

int majority_element(vector<int> &numbers, int l, int r) {
    if (l == r) {
        return numbers[l];
    }
    int mid = (l + r) / 2;
    int majority_of_left = majority_element(numbers, l, mid);
    int majority_of_right = majority_element(numbers, mid + 1, r);
    if (count_in_range(numbers, l, r, majority_of_left) > (r - l + 1) / 2)
        return majority_of_left;
    if (count_in_range(numbers, l, r, majority_of_right) > (r - l + 1) / 2)
        return majority_of_right;
    return -1;
}

int MoreThanHalfNum_Solution3(vector<int> &numbers) {
    return majority_element(numbers, 0, numbers.size() - 1);
}

int MoreThanHalfNum_Solution(vector<int> &numbers) {
    int candidate = numbers[0];
    int count = 1;
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] == candidate) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            candidate = numbers[i + 1];
            count++;
        }
    }
    return candidate;
}


int main() {
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int ret = MoreThanHalfNum_Solution(nums);
    return 0;
}