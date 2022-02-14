#include "bits/stdc++.h"

using namespace std;
int countOperations(int num1, int num2) {
    int ret = 0;
    while (num1!=0&&num2!=0){
        if(num1>num2){
            num1-=num2;
        }
        else{
            num2-=num1;
        }
        ret++;
    }
    return ret;

}
int main() {
    int num1 = 3,num2 = 2;
    int ret = countOperations(num1,num2);
    return 0;
}