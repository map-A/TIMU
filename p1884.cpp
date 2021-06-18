#include "bits/stdc++.h"

using namespace std;


int twoEggDrop(int n) {
   int cur = 0;
   int ret =0;
   while(cur<n){
       ret++;
       cur+=ret;
   }
   return ret;

}
int main() {
    int n=6;
    int ret = twoEggDrop(n);
    return 0;
}