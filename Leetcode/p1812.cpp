#include "bits/stdc++.h"

using namespace std;
bool squareIsWhite(string coordinates) {
    int x = coordinates[0]-'a'+1;
    int y = coordinates[1]-'0';
    return (x+y)%2!=0;
}
int main() {

    return 0;
}