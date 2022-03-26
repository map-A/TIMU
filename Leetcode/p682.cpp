#include "bits/stdc++.h"

using namespace std;
int calPoints(vector<string>& ops) {
    int n = ops.size();
    vector<int>ret;
    for (int i = 0; i < n;i++) {
        if (ops[i]=="C") {
            ret.pop_back();
        }
        else if (ops[i] == "D") {
            if(ret.size()>0) ret.push_back (2 * ret.back());
        }
        else if (ops[i] == "+") {
            if(ret.size()>=2)
                ret.push_back(ret.back()+ret[ret.size()-2]);
            else if(ret.size()==1) ret.push_back(ret[0]);
            else continue;
        }
        else {
            ret.push_back(stoi(ops[i]));
        }
    }
    int sum = 0;
    for (auto i : ret) {
        sum += i;
    }
    return sum;
}
int main() {

    return 0;
}