#include "bits/stdc++.h"

using namespace std;
int findComplement(int num) {
    int n=1;
    while((num&n)!=num)
        n=(n<<1)+1;
    return num^n;
}
int main() {

    return 0;
}