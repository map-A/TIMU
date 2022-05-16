#include "bits/stdc++.h"

using namespace std;
char shift(char c,int x){
    return (int)c+x-'0';
}
string replaceDigits(string s) {
    for(int i=1;i<s.size();i+=2){
        s[i] = shift(s[i-1],s[i]);
    }
    return  s;
}


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


int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    arr[0]=1;
    for(int i=1;i<arr.size();i++){
        if(abs(arr[i]-arr[i-1])>1){
            arr[i]=arr[i-1]+1;
        }
    }
    return arr[arr.size()-1];
}



int main() {

    return 0;
}