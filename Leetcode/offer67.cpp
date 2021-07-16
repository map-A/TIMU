#include "bits/stdc++.h"

using namespace std;

int StrToInt(string str) {
    int sign = 1;
    int ret = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            continue;
        } else if (str[i] == '-') {
            sign = -1;
        } else if (str[i] == '+') {
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (ret > 214748364) {
                return 0;
            }
            ret = ret * 10;
            if (sign == 1 && ret == 2147483640 && str[i] > '7') {
                return 0;
            } else if (sign == 0 && ret == 2147483640 && str[i] > '8') {
                return 0;
            }

            ret += (str[i] - '0');
        } else {
            return 0;
        }
    }
    return sign * ret;
}

int main() {
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;
    string str = "-2147483648";
    int ret = StrToInt(str);
    return 0;
}