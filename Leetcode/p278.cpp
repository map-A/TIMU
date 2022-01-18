#include "bits/stdc++.h"

using namespace std;
int firstBadVersion(int n) {
    int l = 0;
    int r = n - 1;
    int mid;
    while(l < r) {
        mid = l + (r - l) / 2;
        if(!isBadVersion(mid+1)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l + 1;

}
int main() {

    return 0;
}