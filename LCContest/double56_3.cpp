#include "bits/stdc++.h"

using namespace std;

bool sumGame(string num) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] == '?')count++;
        else sum += num[i] - '0';
    }

    for (int i = num.size() / 2; i < num.size(); i++) {
        if (num[i] == '?')count--;
        else sum -= num[i] - '0';
    }
    if (count % 2 == 0 && sum + count * 9 / 2 == 0) {
        return false;
    }
    return true;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}