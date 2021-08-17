#include "bits/stdc++.h"

using namespace std;
bool checkRecord(string s) {
    int numsA = 0;
    int max_succesdL = 0;
    bool flag =false;
    int tmp = 0;
    for(auto i:s){
        if(i=='A'){
            numsA++;
            flag = false;
            tmp = 0;
        }
        if(i=='L'&&flag==false){
            flag=true;
            tmp++;
            max_succesdL = max(max_succesdL,tmp);
        }
        else if(i=='L'&&flag==true){
            tmp++;
            max_succesdL = max(max_succesdL,tmp);
        }
        else {
            flag = false;
            tmp = 0;
        }
    }
    return numsA<=1&&max_succesdL<=2;
}
int main() {

    return 0;
}