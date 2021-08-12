#include "bits/stdc++.h"

using namespace std;
vector<int> memLeak(int memory1, int memory2) {
    int crashTime = 1;
    while(crashTime){
        bool flag = true;
        if(memory1>=memory2){
            if(memory1>=crashTime){
                memory1-=crashTime;
                flag = false;
            }
        }
        else{
            if(memory2>=crashTime){
                memory2-=crashTime;
                flag = false;
            }
        }
        if(flag) break;
        crashTime++;
    }
    return {crashTime,memory1,memory2};
}
int main() {

    return 0;
}