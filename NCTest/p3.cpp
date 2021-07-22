#include "bits/stdc++.h"

using namespace std;

int car() {
    return 0;
}

int main() {
    int n, magic;
    cin >> n >> magic;
    vector<int> ordinary;
    string line;
    string temp;
    getline(cin, line);
    //创建字符串流stringstream对象
    stringstream ss(line);

    //根据指定字符分割字符串
    while (getline(ss, temp, ' ')) {
        ordinary.push_back(stoi(temp));
    }

    return 0;
}