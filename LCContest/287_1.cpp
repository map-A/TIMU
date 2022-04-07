#include "bits/stdc++.h"

using namespace std;
int convertTime(string current, string correct) {
    int start_hour = stoi(current.substr(0,2));
    int start_min = stoi(current.substr(3,2));
    int end_hour = stoi(correct.substr(0,2));
    int end_min = stoi(correct.substr(3,2));

    int diff_min = (end_hour-start_hour)*60+(end_min-start_min);

    int ret= 0;
    while (diff_min>0){
        if(diff_min>=60){
            diff_min-=60;
        }
        else if(diff_min>=15){
            diff_min-=15;
        }
        else if(diff_min>=5){
            diff_min-=5;
        }
        else if(diff_min>=1){
            diff_min-=1;
        }
        ret++;
    }
    return ret;

}

int main() {
    string a = "11:00";
    string b = "11:01";
    int ret = convertTime(a,b);
    return 0;
}