#include "bits/stdc++.h"

using namespace std;
vector<long long> sumOfThree(long long num) {
    if(num%3==0){
        return {num/3-1,num/3,num/3+1};
    }
    return {};

}
int main() {

    return 0;
}