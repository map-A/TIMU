#include "bits/stdc++.h"

using namespace std;
int prefixCount(vector<string>& words, string pref) {
    int ret = 0;
    for (int i = 0; i < words.size(); ++i) {
        if(words[i].find(pref)==0){
            ret++;
        }
    }
    return ret;
}

int minSteps(string s, string t) {
    int ret = 0;
    if(s==t) return  ret;
    vector<int>alpha1(26,0);
    vector<int>alpha2(26,0);

    for (int i = 0; i < s.size(); ++i) {
        alpha1[s[i]-'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
        alpha2[t[i]-'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        ret+= abs(alpha1[i]-alpha2[i]);
    }
    return ret;
}


bool help(vector<int>&time,int totalTrips,long long t){
    long long ret = 0;
    for (int i = 0; i < time.size(); ++i) {
        ret+=t/ time[i];
        if(totalTrips<=ret) return true;
    }
    return false;

}
long long minimumTime(vector<int>& time, int totalTrips) {
    sort(time.begin(),time.end());
    long long l = 0,r = 1e16;
    long long mid = (r-l)/2+l;
    while (l<r){
        if(help(time,totalTrips,mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
        mid = (r-l)/2+l;
    }
    return l;
}

int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
    vector<int> minSec(18, INT_MAX / 2);
    for (auto &tire: tires) {
        long time = tire[0];
        for (int x = 1, sum = 0; time <= changeTime + tire[0]; ++x) {
            sum += time;
            minSec[x] = min(minSec[x], sum);
            time *= tire[1];
        }
    }

    vector<int> f(numLaps + 1, INT_MAX);
    f[0] = -changeTime;
    for (int i = 1; i <= numLaps; ++i) {
        for (int j = 1; j <= min(17, i); ++j)
            f[i] = min(f[i], f[i - j] + minSec[j]);
        f[i] += changeTime;
    }
    return f[numLaps];
}

int main() {
    vector<string>words = {"leetcode","win","loops","success"};
    string pref = "code";
    int ret = prefixCount(words,pref);
    return 0;
}