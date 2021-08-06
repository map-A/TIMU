#include "bits/stdc++.h"

using namespace std;

//单调栈
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ret(n, 0);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        //从后向前遍历
        //维持栈顶为向右看到的知道元素
        //当栈顶的元素小于新来的元素，那么一直pop
        while (!s.empty() && T[s.top()] <= T[i]) s.pop();
        if (!s.empty()) ret[i] = s.top() - i;
        s.push(i);
    }
    return ret;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}