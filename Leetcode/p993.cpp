#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

class RecentCounter {
public:
    vector<int>p;
    RecentCounter() {

    }

    int ping(int t) {
        while(p.size()!=0){
            int val = p[0];
            if(val < t-3000){
                p.erase(p.begin());
            }else break;
        }
        p.push_back(t);
        return p.size();
    }
};

int main() {
    return 0;
}
