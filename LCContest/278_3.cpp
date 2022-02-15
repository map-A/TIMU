#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int mult = 1;   // power^k mod modulo
        int n = s.size();
        int pos = -1;   // 第一个符合要求子串的起始下标
        int h = 0;   // 子串哈希值
        // 预处理计算最后一个子串的哈希值和 power^k mod modulo
        for (int i = n - 1; i >= n - k; --i) {
            h = ((long long)h * power + (s[i] - 'a' + 1)) % modulo;
            if (i != n - k) {
                mult = (long long)mult * power % modulo;
            }
        }
        if (h == hashValue) {
            pos = n - k;
        }
        // 向前计算哈希值并尝试更新下标
        for (int i = n - k - 1; i >= 0; --i) {
            h = ((h - (long long)(s[i+k] - 'a' + 1) * mult % modulo + modulo) * power + (s[i] - 'a' + 1)) % modulo;
            if (h == hashValue) {
                pos = i;
            }
        }
        return s.substr(pos, k);
    }
};

int main() {

    return 0;
}