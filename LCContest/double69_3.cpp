#include "bits/stdc++.h"

using namespace std;

int longestPalindrome(vector<string> &words) {
    // a: 统计 形如 “ab”
    // b：统计 所有 形如 “aa” 出现的次数（包括 奇数次 和 偶数次）
    // c：统计 奇数次 “aa” 出现的个数
    int a = 0, b = 0, c = 0;
    unordered_map<string, int> m;
    for (int i = 0; i < words.size(); ++i)
        m[words[i]]++;
    for (auto &[str,num]:m) {
        if (str[0] == str[1]) {
            if (num& 1) {
                c++;
            }
            b += num;
        }
        else {
            string to = "";
            to += str[1];
            to += str[0];
            if (m.count(to)) {
                //对于“ab” 可以删除 “ba”减少遍历次数，但是要乘2
                a += 2 * min(m[to], num);
                m.erase(to);
            }
        }
    }
    return 2 * (b + a - (c <= 1 ? 0 : c - 1));
}

int main() {

    return 0;
}