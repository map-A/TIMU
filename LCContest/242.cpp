#include "bits/stdc++.h"

using namespace std;
int findMaxSeqChar(string s,char target){
    int ret = INT_MIN;
    int l = 0,r=0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]==target&&flag== false){
            l=i;
            r = i;
            ret = 1;
            flag= true;
        }
        else if(s[i]==target&&flag== true){
            r=i;
            ret =max(ret,r-l+1);
        }
        else {
            flag = false;

        }

    }
    return ret;
}
bool checkZeroOnes(string s) {

    //找出连续1
    int one = findMaxSeqChar(s,'1');
    int zero = findMaxSeqChar(s,'0');
    return one>zero;
}


int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    long long hr = llround(hour * 100);
    if (hr <= (n - 1) * 100) {
        return -1;
    }
    int l = 1, r = 1e7;
    while (l < r) {
        int mid = l + (r - l) / 2;
        long long t = 0;
        for (int i = 0; i < n - 1; i++) {
            t += (dist[i] - 1) / mid + 1;//除法向上取整
        }
        t *= mid;
        t += dist[n - 1];
        if (t * 100 <= hr * mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}


bool checkZeroOnes(string s) {

}
int main() {
    string s = "1";
    bool ret = checkZeroOnes(s);
    return 0;
}