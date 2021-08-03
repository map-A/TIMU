#include "bits/stdc++.h"

using namespace std;

long long minimumPerimeter(long long neededApples) {
    long long sum = 0;
    long long i = 0;
    long long total = 0;
    while(total<neededApples){
        i++;
        sum += 24*i-12;
        total+=sum;
    }
    return (i)*8;
}
int main() {
    vector<int> milestone = {5, 5, 1};
    long long ret = numberOfWeeks(milestone);
    return 0;
}