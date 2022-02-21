#include "bits/stdc++.h"

using namespace std;
int countEven(int num) {
    int count = 0;
    for(int k = 2; k <= num; k++){
        int sum = 0, i = k;
        while(i > 0){
            sum += i % 10;
            i /= 10;
        }
        if((sum & 1) == 0){
            count++;
        }
    }
    return count;
}
int main() {

    return 0;
}