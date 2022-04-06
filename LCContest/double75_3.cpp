#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

long long combination(string s, string t) {
    //niubi
    long long a = 0, b = 0, c = 0;
    for (char x: s) {
        if (x == t[2]) c += b;// 统计t[0]t[1]t[2]一起出现组合的次数
        if (x == t[1]) b += a;// 统计t[0]t[1]一起出现组合的次数
        if (x == t[0]) a += 1;// 统计t[0]字符出现的次数
    }
    return c;
}

long long numberOfWays(string s) {
    return combination(s, "101") + combination(s, "010");
}

int main() {
    string s = "11100";
    int ret = numberOfWays(s);
    return 0;
}