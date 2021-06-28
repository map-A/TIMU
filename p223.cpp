#include "bits/stdc++.h"

using namespace std;
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    //Todo: we need to finish tomorrow.
    int area1 = (ax2-ax1)*(ay2-ay1);
    int area2 = (bx2-bx1)*(by2-by1);
    if(ax2<=bx1||by1>=ay2||ay1>by2||ax1>=bx2){
        return area1+area2;
    }
    int topX = min(bx2,ax2),topY = min(by2,ay2);
    int bottomX = max(bx1,ax1),bottomY=max(ay1,by1);
    return area1-(topX-bottomX)*(topY-bottomY)+area2;
}
int main() {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    int ret =  computeArea(ax1,ay1, ax2, ay2, bx1, by1,bx2, by2);
    return 0;
}