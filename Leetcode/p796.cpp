#include "bits/stdc++.h"

using namespace std;
bool rotateString(string A, string B) {
    int len = A.length();
    if(A==""&&B=="")
        return true;
    for(int i=0;i<len;i++){
        A = helper(A);
        if(A==B)
            return true;
    }
    return false;
}
string helper(string A){
    char a = A[0];
    A.erase(0,1);
    A+=a;
    return A;
}
int main() {

    return 0;
}