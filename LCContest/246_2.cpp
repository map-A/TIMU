#include "bits/stdc++.h"

using namespace std;

int numberOfRounds(string startTime, string finishTime) {
    int start_hour = stoi(startTime.substr(0, 2));
    int start_min = stoi(startTime.substr(3, 2));
    int end_hour = stoi(finishTime.substr(0, 2));
    int end_min = stoi(finishTime.substr(3, 2));

    int s_t = start_hour*60+start_min;
    int e_t = end_hour*60+end_min;
    if(e_t<s_t)e_t+=24*60;
    int cnt = 0;
    for(int i=s_t/15*15;i<e_t;i+=15){
        if(s_t<=i&&i<=e_t&&s_t<i+15&&i+15<=b){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string hour = "12:01";
    string hour1 = "12:44";
    auto ret = numberOfRounds(hour, hour1);
    return 0;
}