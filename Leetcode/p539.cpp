#include "bits/stdc++.h"

using namespace std;
int strToTimeMin(string &str)
{
    int timeHour = 0;
    int timeMin = 0;

    timeHour = stoi(str.substr(0,2));
    timeMin  = stoi(str.substr(3, 2));

    return (timeHour*60 + timeMin);
}

int findMinDifference(vector<string>& timePoints) {
    int maxMinDay = 24 * 60;
    int timeIdx = 0;
    int ret = 0;
    int timeLen = 0;
    timeLen = timePoints.size();

    vector<int> time(timeLen, 0);

    for (auto &str : timePoints) {
        time[timeIdx] = strToTimeMin(str);
        timeIdx++;
    }

    sort(time.begin(),time.end());

    ret = min(time[timeLen-1] - time[0], time[0]+ maxMinDay- time[timeLen - 1]);
    for (int i = 1; i < timeLen;i++) {
        ret = min(ret, time[i]-time[i-1]);
    }

    return ret;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}