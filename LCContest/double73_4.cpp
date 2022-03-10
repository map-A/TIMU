#include "bits/stdc++.h"

using namespace std;

int minMovesToMakePalindrome(string s) {
    if (s.size() == 0) return 0;
    int cnt = 0, n = s.size();
    string temp;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == s[0] && i != 0) {
            for (int j = 1; j < i; j++) temp += s[j];
            for (int j = i + 1; j < n; j++) temp += s[j];
            cnt += n - i - 1;
            break;
        }
        if (i == 0) {
            cnt += n / 2;
            temp = s.substr(1);
        }
    }
    return cnt + minMovesToMakePalindrome(temp);

}

int main() {

    return 0;
}