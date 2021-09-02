#include "bits/stdc++.h"

using namespace std;
struct cmp{
    bool operator () (pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }
};

class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>seats; //num
    vector<int>vis;
    SeatManager(int n) {
        for(int i=1;i<n+1;i++){
            seats.push(i);
        }
        vis.resize(n,0);
    }

    int reserve() {
        auto seat = seats.top();
        seats.pop();
        vis[seat-1]=1;
        return seat;
    }

    void unreserve(int seatNumber) {
        vis[seatNumber-1]=0;
        seats.push(seatNumber);
    }
};
int main() {

    return 0;
}