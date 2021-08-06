#include "bits/stdc++.h"

using namespace std;
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size;
    vector<int>line;
    double ret = 0;
    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        line.push_back(val);
        int len = line.size();
        if(len<= this->size){
            ret = ret*(len-1)+val;
            ret = ret/len;
        }
        else{
            ret = ret* this->size-line[len- this->size-1]+val;
            ret/= this->size;
        }
        return ret;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}