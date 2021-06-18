#include "bits/stdc++.h"

using namespace std;
vector<int> corpFlightBookings1(vector<vector<int>>& bookings, int n) {
    vector<int>ret(n,0);
    for(int i=0;i<bookings.size();i++){
        for(int j=bookings[i][0];j<=bookings[i][1];j++){
            ret[j-1]+=bookings[i][2];
        }
    }
    return ret;
}
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int>ret(n+1,0);
    for(int i=0;i<bookings.size();i++){
        ret[bookings[i][0]-1]+=bookings[i][2];
        ret[bookings[i][1]]-=bookings[i][2];
    }
    for(int i=1;i<n;i++){
        ret[i]+=ret[i-1];
    }
    return vector<int>(ret.begin(),ret.end()-1);
}
int main() {
    vector<vector<int>>booking = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    vector<int>ret = corpFlightBookings(booking,n);
    return 0;
}