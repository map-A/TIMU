#include "bits/stdc++.h"

using namespace std;
int maxNumberOfBalloons(string text) {
    vector<float>v(5,0);
    for (int i = 0; i<text.length(); i++) {
        if (text[i] == 'b')
            v[0]++;
        else if (text[i] == 'a')
            v[1]++;
        else if (text[i] == 'l')
            v[2] += 0.5;
        else if (text[i] == 'o')
            v[3] += 0.5;
        else if (text[i] == 'n')
            v[4]++;
    }
    int ret = 0;
    float temp = v[0];
    for (int i = 1; i < 5;i++) {

        if (temp < v[i])
            continue;
        else
            temp = v[i];
    }
    ret = (int)temp;
    return ret;
}
int main() {

    return 0;
}