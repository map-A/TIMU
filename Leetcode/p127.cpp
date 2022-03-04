#include "bits/stdc++.h"

using namespace std;

int main() {
    char b[2][3] = {{'1','2','3'},{'1','2','3'}};
    char *p = (char *)b;
    vector<int>a = {1,2,3,4,5};
    set<int>c = {1,2,3};
   // remove(c.begin(),c.end(),3);
    remove(a.begin(),a.end(),2);

   // a.erase(a.begin()+2);
    return 0;
}