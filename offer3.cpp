#include "bits/stdc++.h"

using namespace std;

int duplicate(vector<int> &numbers) {
    map<int, int> m;
    for (int i = 0; i < numbers.size(); i++) {
        if (m[numbers[i]] > 0) {
            return numbers[i];
        }
        m[numbers[i]]++;
    }
    return -1;
}

int duplicate(vector<int> &numbers) {
    if (numbers.empty()) return -1;
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] == numbers[i + 1]) {
            return numbers[i];
        }
    }
    return -1;
}

int duplicate(vector<int> &numbers) {
    int i = 0;
    while (i < numbers.size()) {
        if (numbers[i] == i) {
            i++;
            continue;
        }
        if (numbers[numbers[i]] == numbers[i])
            return numbers[i];
        swap(numbers[i], numbers[numbers[i]]);
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}